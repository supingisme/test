#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <sched.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>

#include "vos_ff_api.h"

#define PORT1 2152
#define PORT2 2153



/* fstack实体 */
fstack_t fstack;

/* UDP  server fd */
int fd_cn_cuup = 0;
int fd_cuup_du = 0;

pthread_t fstack_main_thread; /* fstack模块主线程 */
pthread_t du_main_thread;   /* DU模块主线程 */
pthread_t cuup_main_thread; /* CUUP模块主线程 */


/* 这个函数实际调用方为主函数 main */
int my_recvfrom_callback(int fd, void *buff, size_t buflen, struct sockaddr *from)
{
    struct sockaddr_in *addr = (struct sockaddr_in *)from;
    
    printf("RecvFrom.\n");
    printf("Recv        %s\n", buff);
    printf("Recv Len    %ld\n", buflen);
    printf("Addr Family %d\n", addr->sin_family);
    printf("Addr Port   %u\n", ntohs(addr->sin_port));
    printf("Addr Addr   %s\n", inet_ntoa(addr->sin_addr));

    //一些流程
    //TODO
    
    struct timeval tvbrfore, tvafter;
    long int npkg = 0, nbyte=0, n;
    memset(&tvbrfore, 0, sizeof(struct timeval));
    memset(&tvafter, 0, sizeof(struct timeval));
    
    /* 统计时间 */
    fstack_gettimeval(&tvbrfore);

    while(1) {
        n = fstack_udpsocket_sendto(fd, buff, buflen, (struct sockaddr_in *)from, sizeof(struct sockaddr));
        nbyte += n;
        if(npkg++ > 100000) {
            break;
        }
    }

    /* 统计时间 */
    fstack_gettimeval(&tvafter);
    
    /* 输出此段时间内的速率 */
    fstack_statistic_throughput("Sendto", &tvbrfore, &tvafter, nbyte, npkg-1);

    return 0;
}


static void * fstack_main_task(void*arg)
{
//    int ncpu = 3;
//    cpu_set_t cpuset;
//
//	CPU_ZERO(&cpuset);
//    
//    CPU_SET(ncpu>1?ncpu-1:1, &cpuset);
//    
//    int ret = sched_setaffinity(gettid(), sizeof(cpuset), &cpuset);

    /* fstack参数 */
    int ff_argc = 3;
    char *ff_argv[] = {"vos-f-stack", "-c", "./server.ini"};

    /* 初始化fstack协议栈 */
    fstack_init(&fstack, ff_argc, ff_argv);

    /* 注册一个UDP服务端 */
    fd_cn_cuup = fstack_udpsocket_server(PORT1);
    fd_cuup_du = fstack_udpsocket_server(PORT2);

    
    /* 向协议栈注册fd */
    fstack_register_fd(&fstack, fd_cn_cuup, EPOLLIN);
    fstack_register_fd(&fstack, fd_cuup_du, EPOLLIN);

    /* 挂载接收函数，当接收到消息后，该函数会被调用 */
    fstack_register_recvfrom(&fstack, my_recvfrom_callback);

    
    /* fstack主循环 */
    fstack_main(&fstack);
}


void fstack_initial()
{
//    pthread_attr_t attr;
//    cpu_set_t __cpuset;
//    
//	CPU_ZERO(&__cpuset);
//	CPU_SET(5, &__cpuset);
//
//    if(0 != pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &__cpuset)) {
//        perror("pthread_attr_setaffinity_np error.");
//    }
//    printf("Start Fstack thread.\n");
    pthread_create(&fstack_main_thread, NULL, fstack_main_task, NULL);
}


static void * du_task_tx_pkg(void*arg)
{
    while(1) {
        printf("DU running...\n");
        sleep(10);
    }
}

void du_init()
{
    int ret = -1;
//    pthread_attr_t attr;
//    cpu_set_t __cpuset;
//    
//	CPU_ZERO(&__cpuset);
//	CPU_SET(0, &__cpuset);
//
//    if(0 != pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &__cpuset)) {
//        perror("pthread_attr_setaffinity_np error.");
//    }
//    printf("Start thread.\n");
    if(0 != (ret = pthread_create(&du_main_thread, NULL, du_task_tx_pkg, NULL))) {
        perror("pthread_create error.");
        if(ret == EAGAIN) {
            printf("Insufficient  resources  to  create  another  thread");
        } else if (ret == EINVAL) {
            printf("Invalid settings in attr.");
        } else if (ret == EPERM) {
            printf("No permission to set the scheduling policy and parameters specified in attr");
        }
    }
}

static void * cuup_task_tx_pkg(void*arg)
{
    while(1) {
        printf("CUUP running...\n");
        sleep(10);
        
    }    
}

void cuup_init()
{
    pthread_create(&cuup_main_thread, NULL, cuup_task_tx_pkg, NULL);
}


int main()
{
    fstack_initial();
    
    /* 初始化模块 */
    sleep(1);
    du_init();
    sleep(1);
    cuup_init();

    pthread_setname_np(fstack_main_thread, "fstack-task");
    pthread_setname_np(du_main_thread, "du-task");
    pthread_setname_np(cuup_main_thread, "cuup-task");

    

    while(1) {
        printf("eNB running...\n");
        sleep(10);
    } 
}
