#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
 
 
inline int set_cpu(int i)
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
 
    CPU_SET(i,&mask);
 
    printf("thread %u, i = %d\n", pthread_self(), i);
    if(-1 == pthread_setaffinity_np(pthread_self() ,sizeof(mask),&mask))
    {
        return -1;
    }
    return 0;
}
void *fun(void *i)
{
    if(set_cpu(*(int *)i))
    {
        printf("set cpu erro\n");
    }
    long long a = 0;
    while(1)
    {
        a += rand();
    }
    pthread_exit(NULL);
    return NULL;
}
 
int main (int argc, const char * argv[]) {
    int i;
    int cpu_nums = sysconf(_SC_NPROCESSORS_CONF);
 
    printf("cpu_numbs = %d\n", cpu_nums);
    pthread_t Thread[10];
    int tmp[10];
 
    for(i = 0; i < 10; ++i)
    {
        tmp[i] = i%cpu_nums;
        pthread_create(&Thread[i],NULL,fun, &tmp[i]);
    }
 
 
    for(i = 0; i < 10; ++i)
    {
        pthread_join(Thread[i],NULL);
    }
 
    return 0;
}
