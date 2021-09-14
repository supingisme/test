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

/* UDP  server fd */
int fd_cn_cuup = 0;
int fd_cuup_du = 0;

struct sockaddr_in cnaddr;

pthread_t fstack_main_thread; /* fstack模块主线程 */
pthread_t cuup_main_thread; /* CUUP模块主线程 */

char buf[MAXLINE] = {"I'm CUUP : "ADDR_CUUP};

static struct sockaddr_in dest_addr;


void buffer_free(void *buf) {
//    printf("buffer_free\n");    
}

/* 这个函数实际调用方为主函数 main */
int cuup_recvfrom_callback(int fd, void *buff, size_t buflen, struct sockaddr *from)
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
    
    ff_sendto(fd, buff, buflen, 0, (struct linux_sockaddr *)&cnaddr, sizeof(struct sockaddr_in));

    return 0;
}


static void * fstack_main_task(void*arg)
{
    /* fstack参数 */
    int ff_argc = 5;
    char *ff_argv[] = {"cuup-f-stack", "-p", "0", "-c", "./fstack.ini"};


    /* 初始化fstack协议栈 */
    fstack_init(&fstack, ff_argc, ff_argv);

    /* 注册一个UDP服务端 */
    fd_cn_cuup = fstack_udpsocket_client(ADDR_CN, &cnaddr, PORT_CUUP_CN);
    fd_cuup_du = fstack_udpsocket_server(PORT_CUUP_DU);

    
    /* 向协议栈注册fd */
    fstack_register_fd(&fstack, fd_cn_cuup, EPOLLIN);
    fstack_register_fd(&fstack, fd_cuup_du, EPOLLIN);
    
    /* 挂载接收函数，当接收到消息后，该函数会被调用 */
    fstack_register_recvfrom(&fstack, cuup_recvfrom_callback);
    

    /* fstack主循环 */
    fstack_main(&fstack);
}


void fstack_initial()
{
    pthread_create(&fstack_main_thread, NULL, fstack_main_task, NULL);
    pthread_setname_np(fstack_main_thread, "cuup-fstack");
    sleep(3);
}



int main()
{
    int inform_count = 0;

    fstack_initial();
        

    while(1) {
        printf("CUUP running...\n");
        sleep(8);

#if 1
        fstack_sendto(&fstack, fd_cn_cuup, buf, strlen(buf), 0, 
                    (struct sockaddr*)&cnaddr, sizeof(struct sockaddr_in), 
                    buffer_free, false);
        struct sockaddr_in *addr = (struct sockaddr_in *)&cnaddr;
        inform_count++;

        printf("Inform to CN :(%d)%s:%d %d\n", addr->sin_family, 
                                    inet_ntoa(addr->sin_addr), 
                                    ntohs(addr->sin_port), inform_count);
#endif
    } 
}
