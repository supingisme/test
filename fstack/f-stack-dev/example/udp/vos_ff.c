#include "vos_ff_common.h"
#include "vos_ff_api.h"



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
    
    assert((fstack->epfd = ff_epoll_create(10)) > 0);

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
    
    int nevents = ff_epoll_wait(fs->epfd,  fs->events, MAX_EVENTS, -1);

    for (i = 0; i < nevents; ++i) {
        for ( ifd = 0;ifd<MAX_NR_FD;ifd++ ) {
            if (fs->events[i].data.fd == fs->sockevts[ifd].data.fd) {

                if(fs->events[i].events&EPOLLIN) {
                    printf("EPOLLIN.\n"); 
                    n = ff_recvfrom(fs->sockevts[ifd].data.fd, buf, MAX_LINE, 0,  (struct linux_sockaddr *)&cliaddr, &len);

                    if(fs->recvfrom) {
                        printf("Call fs->recvfrom.\n"); 
                        fs->recvfrom(fs->sockevts[ifd].data.fd, buf, n, (struct sockaddr *)&cliaddr);
                    } else {
                        log_error("fstack_register_recvfrom must be called.\n");
                        return;
                    }
                    
                }
                if(fs->events[i].events&EPOLLOUT) {
                    printf("EPOLLOUT.\n");
                    n = ff_sendto(fs->sockevts[ifd].data.fd, buf, MAX_LINE, 0, (struct linux_sockaddr *)&cliaddr, len);
                }

            } 
        }
    }
}


void fstack_main(fstack_t *fstack)
{
    ff_run(fstack_main_loop, fstack);
}
