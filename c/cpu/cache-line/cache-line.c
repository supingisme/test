/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 10月 27日 星期二 09:42:20 CST. */
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

#define LOOP	100000000L

struct s1 {
	unsigned long int t;
};

/* 缓存行了解一下 64字节 */
struct s2 {
	unsigned long int p1,p2,p3,p4,p5,p6,p7;
	unsigned long int t;
	unsigned long int p8,p9,p10,p11,p12,p13,p14;
};

void show_diff_tv(struct timeval *end, struct timeval *start)
{
	printf("microseconds = %ld\n", (end->tv_sec - start->tv_sec)*1000000 
								+(end->tv_usec - start->tv_usec));
}

void* test_s1(void*arg)
{
    struct s2 *S = arg;
	struct timeval tv1, tv2;
	unsigned long int i;

	gettimeofday(&tv1, NULL);

	for(i=0;i<LOOP;i++)	
		S->t += 1;

	gettimeofday(&tv2, NULL);
	show_diff_tv(&tv2, &tv1);

    pthread_exit(NULL);
}

void* test_s2(void*arg)
{
    struct s2 *S = arg;
    
	struct timeval tv1, tv2;
	unsigned long int i;

	gettimeofday(&tv1, NULL);

	for(i=0;i<LOOP;i++)	
		S->t += 1;

	gettimeofday(&tv2, NULL);
	show_diff_tv(&tv2, &tv1);

    pthread_exit(NULL);
}

void demo0()
{
    struct s1 S1;
	struct s1 S2;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, test_s1, &S1);
    pthread_create(&t2, NULL, test_s1, &S2);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void demo1()
{
    struct s1 S1;
	struct s2 S2;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, test_s1, &S1);
    pthread_create(&t2, NULL, test_s2, &S2);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}



void demo2()
{
    struct s2 S1;
	struct s2 S2;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, test_s2, &S1);
    pthread_create(&t2, NULL, test_s2, &S2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

}


int main()
{
    demo0();
	sleep(1);
    demo1();
	sleep(1);
    demo2();

	sleep(1);
    printf("Done.\n");
}
