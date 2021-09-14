#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

#include "vos_ff_api.h"
#include "ff_api.h"

#include "common.h"



/* fstack实体 */
fstack_t fstack;

/* UDP  fd */
int fd_cuup_du = 0;

pthread_t fstack_main_thread; /* fstack模块主线程 */
pthread_t du_main_thread;   /* DU模块主线程 */
pthread_t cuup_main_thread; /* CUUP模块主线程 */

static struct sockaddr_in dest_addr;

struct sockaddr_in cuupaddr;

char buf[MAXLINE] = {"I'm DU : "ADDR_DU};


void buffer_free(void *buf) {
//    printf("buffer_free\n");    
}

/* 这个函数实际调用方为主函数 main */
int du_recvfrom_callback(int fd, void *buff, size_t buflen, struct sockaddr *from)
{
    struct sockaddr_in *addr = (struct sockaddr_in *)from;
    memcpy(&dest_addr, addr, sizeof(struct sockaddr_in));
    
    printf("RecvFrom.\n");
    printf("Recv        %s\n", buff);
    printf("Recv Len    %ld\n", buflen);
    printf("Addr Family %d\n", addr->sin_family);
    printf("Addr Port   %u\n", ntohs(addr->sin_port));
    printf("Addr Addr   %s\n", inet_ntoa(addr->sin_addr));

    //一些流程
    //TODO

    return 0;
}


static void * fstack_main_task(void*arg)
{
    /* fstack参数 */
    int ff_argc = 5;
    char *ff_argv[] = {"du-f-stack", "-p", "1", "-c", "./fstack.ini"};

    const char *ipv4;

    /* 初始化fstack协议栈 */
    fstack_init(&fstack, ff_argc, ff_argv);

    /* 注册一个UDP服务端 */
    fd_cuup_du = fstack_udpsocket_client(ADDR_CUUP, &cuupaddr, PORT_CUUP_DU);

   
    /* 向协议栈注册fd */
    fstack_register_fd(&fstack, fd_cuup_du, EPOLLIN);
    
    /* 挂载接收函数，当接收到消息后，该函数会被调用 */
    fstack_register_recvfrom(&fstack, du_recvfrom_callback);

    
    /* fstack主循环 */
    fstack_main(&fstack);
}


void fstack_initial()
{
    pthread_create(&fstack_main_thread, NULL, fstack_main_task, NULL);
    pthread_setname_np(fstack_main_thread, "du-fstack");
    sleep(3);
}




int main()
{
    int inform_count = 0;
    
    fstack_initial();
    

    while(1) {
        printf("DU running...\n");
        sleep(8);
#if 1
        fstack_sendto(&fstack, fd_cuup_du, buf, strlen(buf), 0, 
                    (struct sockaddr*)&cuupaddr, sizeof(struct sockaddr_in), 
                    buffer_free, false);
        inform_count++;
        struct sockaddr_in *addr = (struct sockaddr_in *)&cuupaddr;
        
        printf("Inform to CUUP :(%d)%s:%d %d\n", addr->sin_family, 
                                    inet_ntoa(addr->sin_addr), 
                                    ntohs(addr->sin_port), inform_count);
#endif
    } 
}
