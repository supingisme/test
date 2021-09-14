
#include <pthread.h>
#include <stdio.h>
#include <time.h>

pthread_cond_t cond2;
pthread_condattr_t cond2attr;

#define test(clk_id) {\
    printf("%s:%d\n", #clk_id, clk_id);\
}

static void print_clock(char *msg, clockid_t cid)
{
    struct timespec ts;

    printf("%s", msg);
    if (clock_gettime(cid, &ts) == -1)
        fprintf(stderr, "clock_gettime");
    printf("%4ld.%03ld\n", ts.tv_sec, ts.tv_nsec / 1000000);
}


void* test_task_fn(void* unused)
{
	printf("test_task_fn.\n");

    for (;;)
        continue;
    
    static int status = 12121;
    
    pthread_exit(&status);
	return NULL;
}

/* The main program. */
int main ()
{
    int *pstatus;
    int ret;
    clockid_t clockid=0;
	pthread_t thread_id;

	pthread_create(&thread_id, NULL, test_task_fn, NULL);
    
    printf("Main thread sleeping\n");
    sleep(1);

    
    ret = pthread_getcpuclockid(thread_id, &clockid);
    print_clock("  Child", clockid);


    ret = pthread_getcpuclockid(pthread_self(), &clockid);
    print_clock(" Parent", clockid);
    print_clock("Process", CLOCK_PROCESS_CPUTIME_ID);
    
    
	pthread_join(thread_id, (void**)&pstatus);

    printf("pstatus = %d\n", *pstatus);

    
	return 0;
}






