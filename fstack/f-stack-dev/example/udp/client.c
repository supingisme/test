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
#include <assert.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/ip.h>


int sockfd;
struct sockaddr_in servaddr;

socklen_t servlen = sizeof(struct sockaddr_in);

int epfd;
struct epoll_event ev;
struct epoll_event events[MAX_EVENTS];

char sendline[MAXLINE], recvline[MAXLINE + 1];

struct timeval tvbrfore, tvafter;
long int npkg = 0, nbyte=0;


int udpsocket_client(const char *ipv4, struct sockaddr_in *servaddr)
{
    int sockfd, t;
    
    bzero(servaddr, sizeof(struct sockaddr_in));
    servaddr->sin_family = AF_INET;
    servaddr->sin_port = htons(PORT);
    
    if((t = inet_pton(AF_INET, ipv4, &servaddr->sin_addr)) <= 0)
    {
        log_error("inet_pton error.\n");
        return -1;
    }
    if((sockfd = ff_socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        log_error("ff_socket error.\n");
        return -1;
    }
    
    return sockfd;
}


int client_loop(void *arg)
{
    int n;
    
    struct sockaddr_in *servaddr = (struct sockaddr_in *)arg;
    
    
    /* Wait for events to happen */
    int nevents = ff_epoll_wait(epfd,  events, MAX_EVENTS, -1);
    int i, len;
    len = sizeof(struct sockaddr_in);
    
    
    for (i = 0; i < nevents; ++i) {
        if (events[i].data.fd == sockfd) {
            /* 统计时间 */
            gettimeval(&tvbrfore);
            while(1) {
                if((n = ff_recvfrom(sockfd, recvline, MAXLINE, 0,  (struct linux_sockaddr *)servaddr, &len)) < 0)
                {
                    log_warn("recvfrom error\n");
                } else {
                    nbyte += n;
                    if(npkg++ > 10000) {
                        break;
                    }
                    
                }
            }
            /* 统计时间 */
            gettimeval(&tvafter);
            /* 输出此段时间内的速率 */
            statistic_throughput("RecvFrom", &tvbrfore, &tvafter, nbyte, npkg-1);
        }
    }
}


int main(int argc, char *argv[])
{
#if HAVE_FSTACK==1
    ff_init(argc, argv);
#endif
    
    log_warn("Init socket.\n");
    
    sockfd = udpsocket_client(TEST_ADDR1, &servaddr);

    
    assert((epfd = ff_epoll_create(10)) > 0);
    ev.data.fd = sockfd;
    ev.events = EPOLLIN;
    ff_epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);

    log_warn("Sockfd %d Wait for a Client...\n", sockfd);
    
    log_warn("Ready to sendto.\n");
    if(ff_sendto(sockfd, sendline, MAXLINE, 0, (struct linux_sockaddr *)&servaddr, servlen) < 0)
    {
        log_warn("sendto error\n");
        exit(1);
    } else {
        log_warn("Client send %d: %s\n", sockfd, sendline);
    }
    
#if HAVE_FSTACK==1
    log_warn("Ready to ff_run.\n");
    ff_run(client_loop, &servaddr);
#else
    client_loop(&servaddr);
#endif

    return 1;
}

