#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_cond_t cond;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_condattr_t cond2attr;



void print_clockid(clockid_t clockid){
    switch(clockid){
    /* Identifier for system-wide realtime clock.  */
    case CLOCK_REALTIME: printf("Identifier for system-wide realtime clock.\n");break;
    /* Monotonic system-wide clock.  */
    case CLOCK_MONOTONIC: printf("Monotonic system-wide clock.\n");break;
    /* High-resolution timer from the CPU.  */
    case CLOCK_PROCESS_CPUTIME_ID: printf("High-resolution timer from the CPU.\n");break;
    /* Thread-specific CPU-time clock.  */
    case CLOCK_THREAD_CPUTIME_ID: printf("Thread-specific CPU-time clock.\n");break;

    default: printf("Unknown clock.\n");break;
    }
}

void* thread_task1(void* arg)
{
    pthread_mutex_lock(&mutex);

    pthread_cond_wait(&cond,&mutex);

    printf("thread_task1 start working\n");
    sleep(2);
    printf("thread_task1 works over\n");
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* thread_task2(void* arg)
{
    pthread_mutex_lock(&mutex);

    pthread_cond_wait(&cond,&mutex);

    printf("thread_task2 start working\n");
    sleep(2);
    printf("thread_task2 works over\n");
    pthread_mutex_unlock(&mutex);

    return NULL;
}


int main()
{
    clockid_t clockid=-1;
    
    pthread_condattr_init(&cond2attr);
    pthread_condattr_getclock(&cond2attr, &clockid);
    print_clockid(clockid);
    
    pthread_condattr_setclock(&cond2attr, CLOCK_MONOTONIC);
    pthread_condattr_setpshared(&cond2attr, PTHREAD_PROCESS_SHARED);

    pthread_condattr_getclock(&cond2attr, &clockid);
    print_clockid(clockid);
    
    pthread_cond_init(&cond, &cond2attr);
    
    pthread_t thread_1,thread_2;
    pthread_create(&thread_1,NULL,thread_task1,NULL);
    pthread_create(&thread_2,NULL,thread_task2,NULL);
    
    sleep(1);

    pthread_cond_signal(&cond);
    sleep(1);
    pthread_cond_signal(&cond);



    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);

    return 0;

}


