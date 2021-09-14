//pthread_attr_setschedpolicy,  pthread_attr_getschedpolicy - set/get scheduling policy attribute in thread
//attributes object
//
//SYNOPSIS
#include <pthread.h>

/* Scheduler inheritance.  */
enum
{
  PTHREAD_INHERIT_SCHED,
#define PTHREAD_INHERIT_SCHED   PTHREAD_INHERIT_SCHED
  PTHREAD_EXPLICIT_SCHED
#define PTHREAD_EXPLICIT_SCHED  PTHREAD_EXPLICIT_SCHED
};

//policy
//SCHED_FIFO, SCHED_RR, and SCHED_OTHER


int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy);
int pthread_attr_getschedpolicy(pthread_attr_t *attr, int *policy);

//Compile and link with -pthread.
//RETURN VALUE
//       On success, these functions return 0; on error, they return a nonzero error number.
//<1>.调度策略：
//
//函数pthread_attr_setschedpolicy和pthread_attr_getschedpolicy分别用
//来设置和得到线程的调度策略。

int pthread_attr_getschedpolicy(const pthread_attr_t *, int * policy);
int pthread_attr_setschedpolicy(pthread_attr_*, int policy);
//参数：
//        attr            线程属性变量
//        policy        调度策略   
//若成功返回0，若失败返回-1。
//
//所谓调度策略也就是我们之前在OS中所学过的那些调度算法：
//SCHED_FIFO    ：先进先出
//SCHED_RR       ：轮转法
//SCHED_OTHER    ：其他方法
//
//SCHED_OTHER是不支持优先级使用的,而SCHED_FIFO和SCHED_RR
//支持优先级的使用,他们分别为1和99,数值越大优先级越高.
//
//注意：
//        > 此处的SCHED_FIFO是允许被高优先级抢占的！
//        > 也就是有高优先级的必须先运行
//        > SCHED_RR是设置一个时间片
//        > 当有SCHED_FIFO或SCHED_RR策赂的线程在一个条件变量
//        上等持或等持加锁同一个互斥量时，它们将以优先级顺序被唤
//        醒。即，如果一个低优先级的SCHED_FIFO线程和一个高优先
//        织的SCHED_FIFO线程都在等待锁相同的互斥且，则当互斥量
//        被解锁时，高优先级线程将总是被首先解除阻塞。

