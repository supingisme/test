#include "vos_ff_common.h"
#include "vos_ff_api.h"


static long int tx_npkg = 0;
static long int tx_nbyte = 0;
static struct timeval tx_timestart = {0,0};
static struct timeval tx_timeend = {0,0};
static int tx_start_flag = 0;


/**
 *  初始化 fstack 协议栈， 并初始化一个 epoll（kevent）
 *
 *  fstack: fstack 协议栈实体，为申请好的内存
 *  argc:   ff_init 参数个数
 *  argv:   ff_init 参数
 *
 */
int fstack_init(fstack_t *fstack, int argc, char *argv[])
{
    int ret;

    ff_init(argc, argv);
    
    memset(fstack, 0, sizeof(fstack_t));

    log_info("Init pipe.\n");
	 pipe(fstack->pipe_fd);
    
    log_info("Create pipe fp.\n");
	/* 打开管道两端 */
    fstack->pipe_in_fp = fdopen(fstack->pipe_fd[1], "w");
    fstack->pipe_out_fp = fdopen(fstack->pipe_fd[0], "r");
    
    log_info("Create pipe fp. in %d, out %d\n", 
                    fileno(fstack->pipe_in_fp), 
                    fileno(fstack->pipe_out_fp));

    assert((fstack->epfd = ff_epoll_create(10)) > 0);
    assert((fstack->pipe_epfd = epoll_create(10)) > 0);
    

    /* 将管道的fd加入epoll */
    struct epoll_event pipe_ev;
	pipe_ev.data.fd = fileno(fstack->pipe_out_fp);
	pipe_ev.events = EPOLLIN;
	ret = epoll_ctl(fstack->pipe_epfd, EPOLL_CTL_ADD, 
                    fileno(fstack->pipe_out_fp), &pipe_ev);
    if(ret < 0) {
        log_error("Epoll ctl ADD error. fd = %d\n", 
                    fileno(fstack->pipe_out_fp));
    }

    return ret;

}



/**
 *  向fstack协议栈实体中注册一个fd
 *  这个fd可以为 fstack_udpsocket_client 或 fstack_udpsocket_server 创建的
 *
 *  fstack: fstack实体
 *  fd:     需要监听的fd
 *  event:  epoll event， 可以为如下选项
 *          EPOLLIN     连接到达；有数据来临；
 *          EPOLLPRI    外带数据
 *          EPOLLOUT    有数据要写
 *          EPOLLERR    只有采取动作时，才能知道是否对方异常。
 *                      即对方突然断掉，是不可能有此事件发生的。
 *                      只有自己采取动作（当然自己此刻也不知道），read，write时，
 *                      出EPOLLERR错，说明对方已经异常断开。
 *          EPOLLHUP    使用EPOLLIN，read返回0，删除掉事件，关闭close(fd);
 *          EPOLLRDNORM
 *          EPOLLRDBAND
 *          EPOLLWRNORM
 *          EPOLLWRBAND
 *          EPOLLMSG
 */
int fstack_register_fd(fstack_t *fstack, int fd, uint32_t event)
{    
    static int idx_fd = 0;

    fstack->sockevts[idx_fd].data.fd = fd;
    fstack->sockevts[idx_fd].events = event;
    int ret = ff_epoll_ctl(fstack->epfd, EPOLL_CTL_ADD, fd, &fstack->sockevts[idx_fd]);

    log_info("Register: fd %d, 0x04x\n", fd, event);

    idx_fd++;
    if(MAX_NR_FD <= idx_fd) {
        log_error("Number of fd must less than %d.\n", MAX_NR_FD);
        exit(1);
    }
    
    return ret;
}

/**
 *  从fstack协议栈实体中删除一个fd
 *  这个fd可以为 fstack_udpsocket_client 或 fstack_udpsocket_server 创建的
 *
 *  fstack: fstack实体
 *  fd:     需要监听的fd
 */
int fstack_unregister_fd(fstack_t *fstack, int fd)
{
    int ret = ff_epoll_ctl(fstack->epfd, EPOLL_CTL_DEL, fd, NULL);

    return ret;
}



int fstack_register_recvfrom(fstack_t *fstack, fstack_recvfrom_fn recvfrom)
{
    fstack->recvfrom = recvfrom;

    return 0;
}



static int fstack_main_loop(void*arg)
{
    int i, n, ifd;
    fstack_t *fs = (fstack_t *)(arg);
    
    static char buf[MAX_LINE] = {0};
    
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    
    int nevents = ff_epoll_wait(fs->epfd,  fs->events, MAX_EVENTS, 0);

    for (i = 0; i < nevents; ++i) {
        /* Sockfd */
        for ( ifd = 0;ifd<MAX_NR_FD;ifd++ ) {
            if (fs->events[i].data.fd == fs->sockevts[ifd].data.fd) {

                if(fs->events[i].events&EPOLLIN) {
//                    printf("EPOLLIN.\n"); 
                    n = ff_recvfrom(fs->sockevts[ifd].data.fd, buf, 
                                    MAX_LINE, 0,  
                                    (struct linux_sockaddr *)&cliaddr, &len);

                    if(fs->recvfrom) {
//                        printf("Call fs->recvfrom.\n"); 
                        fs->recvfrom(fs->sockevts[ifd].data.fd, buf, n, 
                                        (struct sockaddr *)&cliaddr);
                    } else {
                        log_error("fstack_register_recvfrom must be called.\n");
                        return 1;
                    }                    
                }
            } 
        }
    }

#if 1
    /* fstack线程异步发送sendto */
    nevents = epoll_wait(fs->pipe_epfd,  fs->events, MAX_EVENTS, 0);

    for (i = 0; i < nevents; ++i) {

        /* 管道消息 */
        if(fs->events[i].data.fd == fileno(fs->pipe_out_fp) 
            && fs->events[i].events&EPOLLIN) {
            
            int n = read(fileno(fs->pipe_out_fp), buf, MAX_LINE);
            struct udp_msg_pipe_param *udp_param = (struct udp_msg_pipe_param *)buf;
            if(udp_param->magicnum != PMSG_MAGIC_NUM) {
                continue;
            }
            
            //这里调用实际发包函数
            n = ff_sendto(udp_param->sockfd, udp_param->buf, udp_param->len, udp_param->flags, (struct linux_sockaddr *)&udp_param->to, udp_param->tolen);
            
            if(udp_param->buf_need_free && udp_param->buf_free && udp_param)
                udp_param->buf_free(udp_param->buf);
                        
            if(tx_start_flag == 0) {
                gettimeval(&tx_timestart);
            }
            tx_start_flag = 1;
            tx_npkg++;
            tx_nbyte+=n;
        }
    }

    
    gettimeval(&tx_timeend);

    if(tx_npkg == 100000) {    
        statistic_throughput("FF TX", &tx_timestart, &tx_timeend, tx_nbyte, tx_npkg);
        
        memset(&tx_timestart, 0, sizeof(struct timeval));
        memset(&tx_timeend, 0, sizeof(struct timeval));
        
        tx_start_flag = 0;
        tx_npkg = tx_nbyte = 0;
    }
#endif

    return 1;
}


void fstack_main(fstack_t *fstack)
{
    ff_run(fstack_main_loop, fstack);

}
