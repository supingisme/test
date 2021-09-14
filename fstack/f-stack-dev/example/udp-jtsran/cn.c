/**
 *  测试F-Stack的UDP发包速率
 *  作者：荣涛 <rongtao@sylincom.com>
 *  时间：2020年7月16日10:08:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>


#include "common.h"


int sockfd = 0;
int epoll_fd = -1;


void sig_handler(int signum)
{
    printf("Catch ctrl+C(SIGINT) signal.\n");
    close(sockfd);
    exit(1);
}


int cn_udpsocket_server(int port, struct sockaddr_in *srvaddr)
{
    int sockfd, ret;
    
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;    
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("[CN] socket error.");
        return -1;
    }
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,NULL,0);
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEPORT,NULL,0);

    if((ret = bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("[CN] bind error. ret = %d, %s, port %d\n", 
                    ret, strerror(errno), port);
        return -1;
    }
    
    return sockfd;
}


struct sockaddr_in cnaddr;
struct sockaddr_in cuupaddr;
struct sockaddr_in recvaddr;

int main(int argc, char *argv[])
{
    signal(SIGINT, sig_handler);

    int recvcount = 0;
    int sendcount = 0;

    int n, number, i;
    socklen_t servlen = sizeof(cuupaddr);
    struct sockaddr_in *addr;

    struct timeval tvbrfore, tvafter;
    
    long int npkg = 0, nbyte=0;
    
    char sendline[MAXLINE + 1] = {"I'm CN : "ADDR_CN};
    char recvline[MAXLINE + 1];   
    
    sockfd = cn_udpsocket_server(PORT_CUUP_CN, &cnaddr);
    

    printf("[CN]Wait for CUUP connect... fd = %d\n", sockfd);

    while(1) {
        //get a inform message from CUUP
        if((n = recvfrom(sockfd, recvline, MAXLINE, 0, 
                        (struct sockaddr*)&cuupaddr, &servlen)) < 0) {
            perror("[CN]recvfrom CUUP error");
            continue;
        }//if

        recvcount++;
        
        addr = (struct sockaddr_in *)&cuupaddr;
        
        printf("Recv (%d)%s:%d %d\n", addr->sin_family, 
                                    inet_ntoa(addr->sin_addr), 
                                    ntohs(addr->sin_port), recvcount);


        for(i=0;i<3;i++) {
            if((n = sendto(sockfd, sendline, MAXLINE, 0, 
                        (struct sockaddr *)&cuupaddr, servlen)) <= 0) {
                perror("[CN]sendto error");
                continue;
            }//if
            printf("[CN]Send len %d\n", n);
            sendcount++;
            sleep(1);
          }//
    }//while

    close(sockfd);

    return 1;
}
