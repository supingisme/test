/**
 *  F-Stack API封装头文件
 *  作者：荣涛 <rongtao@sylincom.com>
 *  时间：2020年7月30日09:12:22
 */


#ifndef __FSTACK_VOS_H
#define __FSTACK_VOS_H 1

#include "common.h"

#include <pthread.h>

struct fstack_sockparam {
    char threadname[64];
    pthread_t threadid;
    int sockfd;
    int epfd;
    struct epoll_event ev;
    struct epoll_event events[MAX_EVENTS];
    int (*loop)(void *arg);
    void *arg;
};

int fstack_init(int ff_argc, char *const ff_argv[]);


void fstack_add_routine(const char *name,struct fstack_sockparam *sockparam, 
                            int (*loop)(void *arg), void *arg);

int fstack_udpsocket_server();


#endif /*<__FSTACK_VOS_H>*/
