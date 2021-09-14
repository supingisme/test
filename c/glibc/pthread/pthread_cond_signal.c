#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* thread_task1(void* arg)
{
    pthread_mutex_lock(&mutex1);

    pthread_cond_wait(&cond,&mutex1);

    printf("thread_task1 start working\n");
    sleep(2);
    printf("thread_task1 works over\n");
    pthread_mutex_unlock(&mutex1);

    return NULL;
}

void* thread_task2(void* arg)
{
    pthread_mutex_lock(&mutex2);

    pthread_cond_wait(&cond,&mutex2);

    printf("thread_task2 start working\n");
    sleep(2);
    printf("thread_task2 works over\n");
    pthread_mutex_unlock(&mutex2);

    return NULL;
}


int main()
{
    pthread_t thread_1,thread_2;
    pthread_create(&thread_1,NULL,thread_task1,NULL);
    pthread_create(&thread_2,NULL,thread_task2,NULL);
    
    sleep(2);

#if 1
    pthread_cond_signal(&cond);
    sleep(1);
    pthread_cond_signal(&cond);
#else
    pthread_cond_broadcast(&cond);
#endif


    sleep(5);

    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);

    return 0;

}

