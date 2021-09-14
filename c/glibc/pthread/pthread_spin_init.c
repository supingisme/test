
#include <pthread.h>
#include <stdio.h>

//pthread_spinlock_t spin1 = PTHREAD_SPIN_INITIALIZER;
pthread_spinlock_t spin2;


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

    pthread_spin_init(&spin2, PTHREAD_PROCESS_SHARED);
    
	pthread_create(&thread_id, NULL, test_task_fn, NULL);

	pthread_join(thread_id, (void**)&pstatus);

    printf("pstatus = %d\n", *pstatus);

    pthread_spin_destroy(&spin2);
    
	return 0;
}


