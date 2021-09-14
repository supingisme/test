/**
 *  基于F-Stack的socket接口 API
 *
 *  作者：荣涛 <rongtao@sylincom.com>
 *  时间：2020年7月30日09:12:22
 */
#ifndef __VOS_FF_SOCKET_H
#define __VOS_FF_SOCKET_H 1

#include <arpa/inet.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#include <netinet/ip.h>



#define MAX_EVENTS 512
#define MAX_LINE 2048
#define MAX_NR_FD   10

typedef int (*fstack_recvfrom_fn)(int fd, void *buff, size_t buflen, struct sockaddr *from);

typedef struct fstack_entity {
    int epfd;
    struct epoll_event sockevts[MAX_NR_FD];
    struct epoll_event events[MAX_EVENTS];
    
    fstack_recvfrom_fn recvfrom;
}fstack_t;




int fstack_init(fstack_t *fstack, int argc, char *argv[]);
void fstack_main(fstack_t *fstack);

int fstack_register_fd(fstack_t *fstack, int fd, uint32_t event);
int fstack_unregister_fd(fstack_t *fstack, int fd);


int fstack_register_recvfrom(fstack_t *fstack, fstack_recvfrom_fn recvfrom);


int fstack_udpsocket_server(int port);
int fstack_udpsocket_client(const char *ipv4, struct sockaddr_in *servaddr, int port);
int fstack_udpsocket_sendto(int fd, void *buff, size_t buflen, struct sockaddr_in *dstaddr, socklen_t len);


int fstack_tcpsocket_server(int port);
int fstack_tcpsocket_client(const char *ipv4, struct sockaddr_in *servaddr, int port);


inline long int fstack_gettimeval(struct timeval *tv);
inline void fstack_statistic_throughput(char *description, 
            struct timeval *before, struct timeval *after, unsigned long int bytes, long int npkg);



#endif /*<__VOS_FF_SOCKET_H>*/
