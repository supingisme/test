/**
 *  F-Stack API封装
 *  作者：荣涛 <rongtao@sylincom.com>
 *  时间：2020年7月30日09:12:22
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

#include <sys/socket.h>
#include <netinet/ip.h>
#include <sys/epoll.h>

#include "server-vos.h"

char buf[MAXLINE] = {"100000000"};

void sig_handler(int signum)
{
    printf("Catch ctrl+C(SIGINT) signal.\n");
    exit(1);
}

int ff_udpserver_loop(void *arg)
{
    struct fstack_sockparam *sockparam = (struct fstack_sockparam *)arg;
    
    int n;
	socklen_t len;
    
	struct sockaddr_in cliaddr;
    struct timeval tvbrfore, tvafter;
    
    /* Wait for events to happen */
    int nevents = ff_epoll_wait(sockparam->epfd,  sockparam->events, MAX_EVENTS, -1);
    int i;
    len = sizeof(cliaddr);
        
    for (i = 0; i < nevents; ++i) {
        /* 如果是UDP的服务端， 接收一个来自客户端的消息，
            获取客户端地址，用于向客户端发送数据测发送速率 */
        if (sockparam->events[i].data.fd == sockparam->sockfd) {
    
    
            if((n = ff_recvfrom(sockparam->sockfd, buf, MAXLINE, 0,  (struct linux_sockaddr *)&cliaddr, &len)) < 0)
            {
                log_warn("recvfrom error\n");
            } else {
                log_warn("Server recv   %s\n", buf);
                log_warn("Client Family %d\n", cliaddr.sin_family);
                log_warn("Client Port   %u\n", ntohs(cliaddr.sin_port));
                log_warn("Client Addr   %s\n", inet_ntoa(cliaddr.sin_addr));
                
                long int npkg = 0, nbyte=0;
                long int Nkpg = atol(buf);
                
                Nkpg = Nkpg>1000000?Nkpg:1000000;
                
                log_warn("Ready Send N Pkg %ld\n", Nkpg);

                /* 告诉我向客户端发了啥 */
                strcpy(buf, "[FSTACK-DPDK][RongTao Test][牛逼了老哥]");

                /* 统计时间 */
                gettimeval(&tvbrfore);
                
                /* 循环发包，测速率 */
                while(1) {
                    if((n = ff_sendto(sockparam->sockfd, buf, MAXLINE, 0, (struct linux_sockaddr *)&cliaddr, len)) < 0)
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
}




int ff_argc = 3;
char *const ff_argv[] = {"vos-f-stack", "-c", "./server.ini"};


static struct fstack_sockparam udpserver;

int main(int argc, char *argv[])
{
    signal(SIGINT, sig_handler);
    
    fstack_init(ff_argc, ff_argv);
    log_warn("Init fstack.\n");
        
    udpserver.sockfd = fstack_udpsocket_server();
    
    log_warn("Init fstack udp sockfd = %d.\n", udpserver.sockfd);
    
    fstack_add_routine("fstack-udp",&udpserver, ff_udpserver_loop, &udpserver);
    
    
    log_warn("Running...\n");
    while(1)sleep(1);
}


