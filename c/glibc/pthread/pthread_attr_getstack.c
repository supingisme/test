#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<errno.h>
void *thread(void *arg)
{
    printf("thread run\n");
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    void *stack;
    size_t stacksize;
    pthread_attr_getstack(&attr,&stack, &stacksize);
    printf("%x stacksize:%u",stack,stacksize);

    
    return ((void *)0);
}
int main(void)
{
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    void *stack;
    size_t stacksize;
    pthread_create(&tid,&attr,thread,NULL);
    pthread_attr_getstack(&attr,&stack, &stacksize);
    printf("%x stacksize:%u",stack,stacksize);
    sleep(2);
    return 0;
}

