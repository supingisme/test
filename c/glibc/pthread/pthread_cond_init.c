
#include <pthread.h>
#include <stdio.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2;


void* test_task_fn(void* unused)
{
	printf("test_task_fn.\n");

    static int status = 12121;
    
    pthread_exit(&status);
	return NULL;
}

/* The main program. */
int main ()
{
    int *pstatus;
	pthread_t thread_id;

    pthread_cond_init(&cond2, NULL);
    
	pthread_create(&thread_id, NULL, test_task_fn, NULL);

	pthread_join(thread_id, (void**)&pstatus);

    printf("pstatus = %d\n", *pstatus);

    pthread_cond_destroy(&cond2);
    
	return 0;
}

