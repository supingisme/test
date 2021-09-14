#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<errno.h>

pthread_attr_t attr;

void *thread(void *arg)
{
    printf("thread run\n");
    return ((void *)0);
}
int main(void)
{
    pthread_t tid;
    void *stack;
    size_t stacksize;
    pthread_attr_init(&attr);
    stack=malloc(1024);
    pthread_attr_setstack(&attr,stack,1024);
    pthread_create(&tid,&attr,thread,NULL);

    sleep(1);;
    
    pthread_attr_getstack(&attr,&stack, &stacksize);
    printf("%x stacksize:%u\n",stack,stacksize);
    sleep(2);
    return 0;
}

