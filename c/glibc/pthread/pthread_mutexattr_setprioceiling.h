#include <pthread.h>

////get  and  set  the  prioceiling
//attribute of the mutex attributes object (REALTIME THREADS)
int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *attr, int * prioceiling);
int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *attr, int prioceiling);

//pthread_mutexattr_getprioceiling（）和pthread_mutexattr_setprioceiling（）函数应分别获取并设置attr所指
//向的互斥对象的优先级上限属性，该对象先前是由函数pthread_mutexattr_init（）创建的。
//
//prioceiling属性包含初始化互斥的优先级上限。 封顶的值在SCHED_FIFO定义的最大优先级范围内。
//
//
//prioceiling属性定义了已初始化互斥锁的优先级上限，这是执行互斥锁保护的关键部分的最低优先级。 
//为了避免优先级倒置，互斥锁的优先级上限应设置为高于或等于可能锁定该互斥锁的所有线程的最高优先级的优先级。 
//封顶的值在SCHED_FIFO调度策略定义的最大优先级范围内。


