#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sched.h>

#define MAXITEMS	100*10000
#define MAXTHREADS	100
#define min(a, b)  a<b?a:b

int nitems;
struct {
	pthread_mutex_t mutex;
	int buff[MAXITEMS];
	int nput;
	int nval;
}shared = {PTHREAD_MUTEX_INITIALIZER};
void *producer(void*), *consumer(void*);


struct Node{
	int count;
	int num;
};

int main(int argc, char **argv)
{
	int i, nthreads;
	struct Node count[MAXTHREADS];

	pthread_t tid_producer[MAXTHREADS], tid_consumer;

	if(argc != 3)
		printf("usage: %s items threads!\n", argv[0]),exit(0);


	nitems = min(atoi(argv[1]), MAXITEMS);	
	nthreads = min(atoi(argv[2]), MAXTHREADS);
	printf("nitems=%d, nthreads=%d\n", nitems, nthreads);


	//for more CPUS, must bind to one cpu 
	int level = pthread_getconcurrency();
	printf("getconcurrency = %d\n", level);

	if(pthread_setconcurrency(nthreads) != 0)
		printf("setconcurrency error:%d,%s\n", errno, strerror(errno)), exit(0);
	else{
		level = pthread_getconcurrency(nthreads);
		printf("after set=%d, getconcurrency = %d\n", nthreads, level);
	}



	for(i=0;i<nthreads;++i){
		count[i].num = i;
		count[i].count = 0;
		if(pthread_create(&tid_producer[i], NULL, producer, &count[i]) != 0)
			printf("create pthread %d error: %d,%s\n", i, errno, strerror(errno)), exit(0);
	}

	for(i=0;i<nthreads;++i){
		pthread_join(tid_producer[i], NULL);
		printf("[%d]  num[%d] = %d\n", i, count[i].num, count[i].count);
	}


	pthread_create(&tid_consumer, NULL, consumer, NULL);
	pthread_join(tid_consumer, NULL);

//	sleep(100);

	return 0;
}


void* producer(void *arg)
{
	pthread_t pid = pthread_self();
//	printf("create pthread %x, val=%d\n", (unsigned int)arg, *(int*)arg);
//	sleep(1);
	struct Node *p = (struct Node*)arg;
	printf("num[%d] = %d\n",  p->num, p->count);
	while(1){
		pthread_mutex_lock(&shared.mutex);
		if(shared.nput >= nitems){
			pthread_mutex_unlock(&shared.mutex);
			return NULL;
		}

		shared.buff[shared.nput] = shared.nval;
		++shared.nput;
		++shared.nval;
//	printf("running pthread %x\n", (unsigned int)arg);
		pthread_mutex_unlock(&shared.mutex);
		p->count++;	
	}

}


void* consumer(void* arg)
{
	int i;
	for(i=0;i<nitems;++i){
		if(shared.buff[i] != i)
			printf("buff[%d] = %d\n", i, shared.buff[i]);
	}

	return NULL;
}


