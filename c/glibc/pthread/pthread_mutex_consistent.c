
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
pthread_mutexattr_t mutexattr;


void memshow(const char *prefix, void *ptr, ssize_t size)
{
    unsigned char *byte = (unsigned char *)ptr;
    unsigned char *line_hdr=NULL;
    int i=0, j=0, cnt=0;
    int line=0;
    for(i=0;i<size;i++){
        if(cnt%16==0) {
            line=printf("%s0x%04x:  ", prefix, cnt);
            line_hdr = byte;
        }

        printf("%02x", *byte);
        
        if(cnt%2)printf(" ");
        byte++;

        cnt++;
        if(cnt%16==0) {
            printf(" | ");
            for(j=0;j<16;j++){
                if(i+j<size){
                    printf("%c", isascii(*line_hdr)?*line_hdr:'.');
                    line_hdr++;
                }
                
            }
            printf("\n");
            fflush(stdout);
        }
    }
    printf("\n");
    fflush(stdout);
}


void* test_task1_fn(void* unused)
{
	printf("test_task1_fn.\n");

    pthread_mutex_lock(&mutex);
    
//    memshow("T1Lock ", &mutex, sizeof(mutex));
    
	printf("task1: .\n");
    pthread_exit(NULL); //线程 task1 退出后，task2线程仍然可以获取锁
    
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
	return NULL;
}


void* test_task2_fn(void* unused)
{
	printf("test_task2_fn.\n");

    pthread_mutex_lock(&mutex);
    
//    memshow("T2Lock ", &mutex, sizeof(mutex));
    
	printf("task2: .\n");
    
    pthread_mutex_unlock(&mutex);

    
    pthread_exit(NULL);
	return NULL;
}


/* The main program. */
int main ()
{
    int *pstatus;
	pthread_t thread_id1, thread_id2;

    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_setrobust(&mutexattr, PTHREAD_MUTEX_ROBUST);
    
    pthread_mutex_init(&mutex, &mutexattr);

    memshow("Before ", &mutex, sizeof(mutex));
    
    pthread_mutex_lock(&mutex);
    memshow("MMLock ", &mutex, sizeof(mutex));
    pthread_mutex_unlock(&mutex);

	pthread_create(&thread_id1, NULL, test_task1_fn, NULL);
	pthread_create(&thread_id2, NULL, test_task2_fn, NULL);



    
	pthread_join(thread_id1, (void**)&pstatus);
    pthread_mutex_consistent(&mutex);
    memshow(" After ", &mutex, sizeof(mutex));
	pthread_join(thread_id1, (void**)&pstatus);


    pthread_mutex_destroy(&mutex);
    
	return 0;
}



