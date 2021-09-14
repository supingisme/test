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

#include <sys/socket.h>
#include <netinet/ip.h>
#include <sys/epoll.h>


int sockfd;

int epfd;
struct epoll_event ev;
struct epoll_event events[MAX_EVENTS];

char buf[MAXLINE] = {"100000000"};


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

int server_loop(void *arg)
{
    int n;
	socklen_t len;
    
	struct sockaddr_in cliaddr;
    struct timeval tvbrfore, tvafter;

    
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
            }
        }
    }

#if HAVE_FSTACK!=1
    }
#endif

}

int main(int argc, char *argv[])
{
    signal(SIGINT, sig_handler);
    
    /* 绑核 */
    setaffinity(7);

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

