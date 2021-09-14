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

int fstack_init(int ff_argc, char *const ff_argv[])
{
    return ff_init(ff_argc, ff_argv);
}


static void * fstack_thread_routine(void *arg)
{
    struct fstack_sockparam *sockparam = (struct fstack_sockparam *)arg;
    
    log_warn("Start fstack thread routine. %s\n", sockparam->threadname);
    log_warn("Sockfd %d Wait for a Client...\n", sockparam->sockfd);
    

    
    assert((sockparam->epfd = ff_epoll_create(10)) > 0);
    sockparam->ev.data.fd = sockparam->sockfd;
    sockparam->ev.events = EPOLLIN;
    ff_epoll_ctl(sockparam->epfd, EPOLL_CTL_ADD, sockparam->sockfd, &sockparam->ev);

    
    ff_run(sockparam->loop, sockparam->arg);
}



void fstack_add_routine(const char *name,struct fstack_sockparam *sockparam, 
                            int (*loop)(void *arg), void *arg)
{
    
    int ret = -1;

    strcpy(sockparam->threadname, name);
    sockparam->loop = loop;
    sockparam->arg = arg;
    
    log_warn("Create udp sock routine.\n");

    fstack_thread_routine(sockparam);
    
//    ret = pthread_create(&sockparam->threadid, NULL, fstack_thread_routine, sockparam);
//    if(ret != 0) {
//        log_error("pthread_create failed.\n");
//        return;
//    }
//
    
//    ret = pthread_setname_np(sockparam->threadid, sockparam->threadname);
//    if(ret != 0) {
//        log_error("pthread_setname_np failed.\n");
//        return;
//    }
    log_warn("Create udp sock routine done.\n");
}


int fstack_udpsocket_server()
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

