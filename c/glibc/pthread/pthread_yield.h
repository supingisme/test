#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>

//pthread_yield - yield the processor
//放弃CPU： 该接口导致调用的线程放弃CPU，
//这个线程被移动到优先级队列的队尾，另一个线程将被运行
int pthread_yield(void);

// yield ：屈服，让出


//也可以看
#include <sched.h>

//sched_yield - yield the processor
//放弃CPU： 该接口导致调用的线程放弃CPU，
//这个线程被移动到优先级队列的队尾，另一个线程将被运行
//int sched_yield(void);



