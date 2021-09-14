#define __USE_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

#define releaseHydrogen() fprintf(stderr, "H")
#define releaseOxygen() fprintf(stderr, "O")

//gcc 1115.foobar-sem.c -std=c99 -pthread




/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
    // User defined data may be declared here.
    sem_t H;
    sem_t O;
    int waitcnt;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    // Initialize user defined data here.
    sem_init(&(obj->H), 0, 2);
    sem_init(&(obj->O), 0, 1);
    obj->waitcnt = 0;
    return obj;
}

void hydrogen(H2O* obj) {   
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    sem_wait(&(obj->H)); 
    releaseHydrogen();
    obj->waitcnt++;
    if(obj->waitcnt==2)
    {
        sem_post(&(obj->O)); 
        obj->waitcnt = 0;
    } 
}

void oxygen(H2O* obj) {    
    // releaseOxygen() outputs "O". Do not change or remove this line.
    sem_wait(&(obj->O)); 
    releaseOxygen();
    sem_post(&(obj->H)); 
    sem_post(&(obj->H)); 
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    sem_destroy(&(obj->H));
    sem_destroy(&(obj->O));
    free(obj);
}



/////////////////////////////////////////////////////////////////////////////////////////////

void *thread_hydrogen(void *arg) {
    H2O* fb = (H2O* )arg;
    hydrogen(fb);
}

void *thread_oxygen(void *arg) {
    H2O* fb = (H2O* )arg;
    oxygen(fb);
}
//pthread_barrier_t b; //屏障


int main(int argc, char *argv[]) {

//    pthread_barrier_init(&b,NULL,3); //初始化屏障

    H2O* h2o = h2oCreate(atoi(argv[1]));
    
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, thread_hydrogen, h2o);
    pthread_create(&t3, NULL, thread_hydrogen, h2o);

    pthread_create(&t2, NULL, thread_oxygen, h2o);

//    pthread_barrier_wait(&b);

//    sleep(1);
    h2oFree(h2o);
}



