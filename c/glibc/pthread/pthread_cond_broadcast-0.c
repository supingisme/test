#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_THREAD_NUM 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* thread_fun(void* arg)
{
    int index = *(int*)arg;
    printf("[%d]thread start up!\n", index);
    pthread_mutex_lock(&mutex);
    printf("[%d]thread wait...\n", index);
    pthread_cond_wait(&cond, &mutex);
    printf("[%d]thread wake up\n", index);
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}
int main()
{
    pthread_t tid[MAX_THREAD_NUM];
 
    for(int i = 0; i < MAX_THREAD_NUM; i++)
    {
        pthread_create(&tid[i], NULL, thread_fun, &i);
        sleep(1);
    }
    sleep(3);
    pthread_cond_signal(&cond);	//唤醒N个线程中的一个
    pthread_cond_broadcast(&cond);	//全部唤醒
    for(int i = 0; i < MAX_THREAD_NUM; ++i)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}

