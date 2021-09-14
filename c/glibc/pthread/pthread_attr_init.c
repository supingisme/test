
#include <pthread.h>
#include <stdio.h>
#include <stdio.h>


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

void* test_task_fn(void* unused)
{
	printf("test_task_fn.\n");
    static int status = 12121;
    pthread_attr_t attr;

    memshow("pthread_attr_t before init", &attr, sizeof(pthread_attr_t));

    pthread_attr_init(&attr);
    
    memshow("pthread_attr_t", &attr, sizeof(pthread_attr_t));

    
    pthread_attr_destroy(&attr);
    pthread_exit(&status);
	return NULL;
}
/* The main program. */
int main ()
{
    int *pstatus;
	pthread_t thread_id;
    
	pthread_create(&thread_id, NULL, test_task_fn, NULL);

	pthread_join(thread_id, (void**)&pstatus);

    printf("pstatus = %d\n", *pstatus);
	return 0;
}


