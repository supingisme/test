#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <pthread.h>

struct timer{
	unsigned long id;
};

unsigned long __f()
{
	unsigned long ret = 0x1212121223232323;
	struct timer *t = malloc(sizeof(struct timer));

	t->id = (unsigned long )t;
	printf("f:    %ld(%p)\n", t->id, (void*)t->id);
	return t->id;
}

void *routiue_fn(void *arg);


void demo1()
{
	pthread_t thread1;
	pthread_create(&thread1, NULL,routiue_fn, NULL);
}

void *routiue_fn(void *arg)
{
	int i;
	unsigned long ret;
	for (i=0;i<10;i++) 
	{
		ret = __f();
		printf("main: %ld(%p)\n", ret, ret);
	}
	while(1)sleep(1);
}

int main()
{
	demo1();
	demo1();
	while(1)sleep(1);
}
