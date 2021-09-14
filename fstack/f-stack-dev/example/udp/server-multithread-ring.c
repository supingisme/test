/**
 *  测试F-Stack的UDP发包速率
 *  作者：荣涛 <rongtao@sylincom.com>
 *  时间：2020年7月16日10:08:34
 */
#include "common.h"

#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <assert.h>
#include <pthread.h>

#include <netinet/ip.h>
#include <sys/epoll.h>


#include "async_ring.h"

typedef struct ring_node {
    int sockfd;
    int sendto_flags;
    struct sockaddr sendto_addr;
    socklen_t sendto_socklen;
    
    size_t tx_len;
    char tx_data[0];
#define TX_LEN(len) (len+sizeof(struct ring_node))    
}*tx_ring_node;


struct msg1 {
    char data[1500];
};

int sockfd;

int epfd;
struct epoll_event ev;
struct epoll_event events[MAX_EVENTS];

char buf[MAXLINE] = {"100000000"};

struct async_ring *tx_ring = NULL;

tx_ring_node tx_data = NULL;


void sig_handler(int signum)
{
    printf("Catch ctrl+C(SIGINT) signal.\n");
    close(sockfd);
    exit(1);
}

int udpsocket_server()
{
    int sockfd;
    
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;    
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    
    if((sockfd = ff_socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        return -1;
    }

    if(ff_bind(sockfd, (struct linux_sockaddr *)&servaddr, sizeof(servaddr))) {
        return -1;
    }
    
    return sockfd;
}

//ssize_t perfstat_ff_sendto(int sockfd, void *buf, size_t len, int flags,
//         const struct linux_sockaddr *to, socklen_t tolen, long int Npkg)
//{
//
//    struct timeval tvbrfore, tvafter;
//
//    int n;
//
//    long int npkg = 0, nbyte=0;
//#if HAVE_FSTACK==1
//    Npkg = Npkg>1000000?Npkg:1000000;
//#else
//    Npkg = Npkg>10000?Npkg:10000;
//#endif
//    
//    log_warn("Ready Send N Pkg %ld\n", Npkg);
//
//    /* 告诉我向客户端发了啥 */
//#define MY_ID   "[FSTACK-DPDK][RongTao Test][牛逼了老哥]"
//    strcpy(buf, MY_ID);
//
//    /* 统计时间 */
//    gettimeval(&tvbrfore);
//    
//    /* 循环发包，测速率 */
//    while(1) {
//        if((n = ff_sendto(sockfd, buf, len, 0, (struct linux_sockaddr *)to, len)) < 0)
//        {
//            log_warn("sendto error");
//            exit(1);
//        } else {
//            nbyte += n;
//            if(npkg++ > Npkg) {
//                break;
//            }
//        }
//    }
//    /* 统计时间 */
//    gettimeval(&tvafter);
//    
//    /* 输出此段时间内的速率 */
//    statistic_throughput("Sendto", &tvbrfore, &tvafter, nbyte, npkg-1);
//}


int server_loop(void *arg)
{
    int n;
	socklen_t len;
    
	struct sockaddr_in cliaddr;
    struct timeval tvbrfore, tvafter;

    tx_ring_node ring_node_data;
    
#if HAVE_FSTACK!=1
    while(1) {
        log_warn("Wait for a Client epoll_wait...\n");
#endif
    
    /* Wait for events to happen */
    int nevents = ff_epoll_wait(epfd,  events, MAX_EVENTS, -1);
    int i;
    len = sizeof(cliaddr);
        
#if HAVE_FSTACK!=1
    log_warn("nevents = %d\n", nevents);
#endif
    for (i = 0; i < nevents; ++i) {
        /* 如果是UDP的服务端， 接收一个来自客户端的消息，
            获取客户端地址，用于向客户端发送数据测发送速率 */
        if (events[i].data.fd == sockfd) {
    
    
            if((n = ff_recvfrom(sockfd, buf, MAXLINE, 0,  (struct linux_sockaddr *)&cliaddr, &len)) < 0)
            {
                log_warn("recvfrom error\n");
            } else {
                log_warn("Server recv   %s\n", buf);
                log_warn("Client Family %d\n", cliaddr.sin_family);
                log_warn("Client Port   %u\n", ntohs(cliaddr.sin_port));
                log_warn("Client Addr   %s\n", inet_ntoa(cliaddr.sin_addr));

                tx_data->sockfd = sockfd;
                memcpy(&tx_data->sendto_addr, &cliaddr, sizeof(cliaddr));
                tx_data->sendto_flags = 0;
                tx_data->sendto_socklen = len;

#if 0
                
                long int npkg = 0, nbyte=0;
                long int Nkpg = atol(buf);
#if HAVE_FSTACK==1
                Nkpg = Nkpg>1000000?Nkpg:1000000;
#else
                Nkpg = Nkpg>10000?Nkpg:10000;
#endif
                
                log_warn("Ready Send N Pkg %ld\n", Nkpg);

                /* 告诉我向客户端发了啥 */
#define MY_ID   "[FSTACK-DPDK][RongTao Test][牛逼了老哥]"
                strcpy(buf, MY_ID);

                /* 统计时间 */
                gettimeval(&tvbrfore);
                
                /* 循环发包，测速率 */
                while(1) {
//                    usleep(1);
//                    better_sleep(0.000000001);
//                    printf("ff_sendto.\n");
                    if((n = ff_sendto(sockfd, buf, MAXLINE, 0, (struct linux_sockaddr *)&cliaddr, len)) < 0)
                    {
                        log_warn("sendto error");
                        exit(1);
                    } else {
                        nbyte += n;
                        if(npkg++ > Nkpg) {
                            break;
                        }
                    }
                }
                /* 统计时间 */
                gettimeval(&tvafter);
                
                /* 输出此段时间内的速率 */
                statistic_throughput("Sendto", &tvbrfore, &tvafter, nbyte, npkg-1);
#endif                
            }
        }
    }

    
    /* 采用ring实现多线程异步发包 */
    static long int ring_tx_npkg = 0, ring_tx_nbyte=0;
    static long int ring_tx_Nkpg = 50000;
    
    static struct timeval ring_tx_tvbrfore, ring_tx_tvafter;

    static bool ring_tx_statistic_restart = true;

    /* 统计时间 */
    if(ring_tx_statistic_restart) {
        ring_tx_statistic_restart = false;
        gettimeval(&ring_tx_tvbrfore);
        ring_tx_npkg = 0;
        ring_tx_nbyte = 0;
    }
    
    while(1) {
        if(async_ring_empty(tx_ring)) {
//            log_error("empty ring.\n");
            break;
        } else {
//            log_warn("dequeue from ring.\n");
            if(async_ring_dequeue(tx_ring, (void**)&ring_node_data) == 0) {
                if(ring_node_data) {
//                    log_warn("dequeue from ring success.\n");
//                    struct sockaddr_in *laddr = &ring_node_data->sendto_addr;
//                    log_warn("dequeue Family %d\n", laddr->sin_family);
//                    log_warn("dequeue Port   %u\n", ntohs(laddr->sin_port));
//                    log_warn("dequeue Addr   %s\n", inet_ntoa(laddr->sin_addr));
                    if((n = ff_sendto(ring_node_data->sockfd, 
                                               ring_node_data->tx_data, 
                                               ring_node_data->tx_len, 
                                               ring_node_data->sendto_flags, 
                                               (struct linux_sockaddr *)&ring_node_data->sendto_addr, 
                                               ring_node_data->sendto_socklen)) < 0) {
                        log_warn("sendto error");
                        exit(1);
                    } else {
                        ring_tx_npkg++;
                        ring_tx_nbyte += n;
                    }
                }
            }
        }
    }

    if(ring_tx_npkg >= ring_tx_Nkpg) {
        ring_tx_statistic_restart = true;

        gettimeval(&ring_tx_tvafter);
        
        /* 输出此段时间内的速率 */
        statistic_throughput("Ring Sendto", 
                &ring_tx_tvbrfore, 
                &ring_tx_tvafter, ring_tx_nbyte, ring_tx_npkg-1);
        
        ring_tx_npkg = 0;
        ring_tx_nbyte = 0;
    }


#if HAVE_FSTACK!=1
    }
#endif

}



void *tx_routine(void*arg){

    unsigned long int count = 0;
    sleep(10);
    tx_ring_node data;
    

    while(1) {
        better_sleep(0.000000000001);
//        log_warn("Tx a package to async_ring \n");
        if(async_ring_full(tx_ring)) {
//            log_error("ring is full, error.\n");
            continue;
        }
        if(async_ring_enqueue(tx_ring, tx_data) != 0) {
//            log_error("Enqueue error.\n");
        } 
        count++;
        if(count >= 50000) {
//            log_warn("total send %ld.\n", count);
            count=0;
            sleep(1);
        }
    }
}



void init_tx_test() {

#define TX_THREAD_NEW(id)   \
    pthread_t txthread_##id; \
    pthread_create(&txthread_##id, NULL, tx_routine, NULL); \
    pthread_setname_np(txthread_##id, "tx-task"#id);

#define TX_THREAD_GRP_NEW(id) \
    TX_THREAD_NEW(id##0); \
    TX_THREAD_NEW(id##1);\
    TX_THREAD_NEW(id##2);\
    TX_THREAD_NEW(id##3);\
    TX_THREAD_NEW(id##4);\
    TX_THREAD_NEW(id##5);\
    TX_THREAD_NEW(id##6);\
    TX_THREAD_NEW(id##7);\
    TX_THREAD_NEW(id##8);\
    TX_THREAD_NEW(id##9);
    
    tx_data = (tx_ring_node)malloc(sizeof(struct ring_node) + sizeof(struct msg1));
    tx_data->tx_len = sizeof(struct msg1);
    
    tx_ring = async_ring_create("tx_ring",4096, 0);

    TX_THREAD_GRP_NEW(0);
    TX_THREAD_GRP_NEW(1);



//    pthread_t txthread1, txthread2, txthread3, txthread4, txthread5;

//    pthread_create(&txthread1, NULL, tx_routine, NULL);
//    pthread_setname_np(txthread1, "tx-task1");
//    pthread_create(&txthread2, NULL, tx_routine, NULL);
//    pthread_setname_np(txthread2, "tx-task2");
//    pthread_create(&txthread3, NULL, tx_routine, NULL);
//    pthread_setname_np(txthread3, "tx-task3");
//    pthread_create(&txthread4, NULL, tx_routine, NULL);
//    pthread_setname_np(txthread4, "tx-task4");
//    pthread_create(&txthread5, NULL, tx_routine, NULL);
//    pthread_setname_np(txthread5, "tx-task5");


}


int main(int argc, char *argv[])
{
    signal(SIGINT, sig_handler);

    init_tx_test();

//    while(1) sleep(1);
//
//    return 0;
    
    /* 绑核 */
//    setaffinity(7);

#if HAVE_FSTACK==1
    ff_init(argc, argv);
#endif

    log_warn("Init socket.\n");
    
    sockfd = udpsocket_server();

    assert((epfd = ff_epoll_create(10)) > 0);
    ev.data.fd = sockfd;
    ev.events = EPOLLIN;
    ff_epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);

    log_warn("Sockfd %d Wait for a Client...\n", sockfd);
    
#if 1

#if HAVE_FSTACK==1
    log_warn("Ready to ff_run.\n");
    ff_run(server_loop, NULL);
#else
    server_loop(NULL);
#endif
#else //直接发送 
    direct_sendto_addr(sockfd, "10.170.6.66", PORT, 10000);
#endif
}


