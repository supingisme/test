
#include <pthread.h>
#include <stdio.h>

void* test_task_fn(void* unused)
{
	printf(">> test_task_fn.\n");

    static  pthread_t threadid;
    
    threadid = pthread_self();
    
    int eret = pthread_equal(pthread_self(), threadid);
    printf(">> Thread %ld vs %ld. eret = %d\n", pthread_self(), threadid, eret);
    
	printf(">> pthread_self = %ld.\n", threadid);
    
    pthread_exit(&threadid);
	return NULL;
}
/* The main program. */
int main ()
{
    int *pstatus;
	pthread_t thread_id;
    pthread_t *threadid_child;
    
	pthread_create(&thread_id, NULL, test_task_fn, NULL);

	pthread_join(thread_id, (void**)&threadid_child);

    printf("threadid_child = %ld\n", *threadid_child);

    int eret = pthread_equal(pthread_self(), *threadid_child);
    printf("Thread %ld vs %ld. eret = %d\n", pthread_self(), *threadid_child, eret);
    
	return 0;
}


