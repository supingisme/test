//pthread_setconcurrency, pthread_getconcurrency - set/get the concurrency level
//
//SYNOPSIS
#include <pthread.h>

//并发级别
int pthread_setconcurrency(int new_level);
int pthread_getconcurrency(void);

//Compile and link with -pthread.
//默认并发级别为0。
//
//并发级别仅对M：N线程实现有意义，因为在任何时候，进程的用户级别线程集的子集都可以绑定到较少数量的内核调度实体。 
//设置并发级别允许应用程序向系统提示应该为有效执行应用程序而提供的内核调度实体的数量。
//
//LinuxThreads和NPTL都是1：1线程实现，因此设置并发级别没有任何意义。 
//换句话说，在Linux上存在这些功能仅仅是为了与其他系统兼容，而对程序的执行没有影响。

