//pthread_setconcurrency, pthread_getconcurrency - set/get the concurrency level
//
//SYNOPSIS
#include <pthread.h>

//设置/获取并发级别
int pthread_setconcurrency(int new_level);
int pthread_getconcurrency(void);

//int pthread_setconcurrency(int new_level);
//new_level一般是当前进程中线程的使用个数，在我们的系统中，往往线程的个数是可以确定下来的，所以一般在
//初始化函数中显示的设置对应的数值。
//如果网友想更加详细的知道它的使用方法，请参考：
//http://opengroup.org/onlinepubs/007908799/xsh/pthread_getconcurrency.html


//Compile and link with -pthread.
//On success, pthread_setconcurrency() returns 0; on error, it returns a nonzero error number.
//
//pthread_getconcurrency() always succeeds, returning the concurrency level  set  by  a  previous  call  to
//pthread_setconcurrency(), or 0, if pthread_setconcurrency() has not previously been called.

