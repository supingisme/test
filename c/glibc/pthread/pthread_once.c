#include<stdio.h>  
#include<pthread.h>

  
pthread_once_t once = PTHREAD_ONCE_INIT;  
  
void once_run(void)  
{  
    printf("once_run in thread %ld.\n", (unsigned int )pthread_self());  
}  
  
void * child1(void * arg)  
{  
    pthread_t tid =pthread_self();  
    pthread_once(&once,once_run);  
}  
  
  
void * child2(void * arg)  
{  
    pthread_t tid =pthread_self();  
    pthread_once(&once,once_run);  
}  
  
int main(void)  
{  
    pthread_t tid1,tid2,tid3,tid4;  


    pthread_create(&tid1,NULL,child1,NULL);  
    pthread_create(&tid2,NULL,child2,NULL);  
    pthread_create(&tid3,NULL,child2,NULL);  
    pthread_create(&tid4,NULL,child2,NULL);  
    sleep(10);  

    return 0;  
  
}

