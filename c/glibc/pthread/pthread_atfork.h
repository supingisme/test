#include <pthread.h>

//register fork handlers
int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void));

//在父进程调用fork函数派生子进程的时候，如果父进程创建了pthread的互斥锁（pthread_mutex_t）对象，
//那么子进程将自动继承父进程中互斥锁对象，并且互斥锁的状态也会被子进程继承下来：
//如果父进程中已经加锁的互斥锁在子进程中也是被锁住的，如果在父进程中未加锁的互斥锁在子进程中也是未加锁的。
//在父进程调用fork之前所创建的pthread_mutex_t对象会在子进程中继续有效，而
//pthread_mutex_t对象通常是全局对象，会在父进程的任意线程中被操作（加锁或者解锁），
//这样就无法通过简单的方法让子进程明确知道被继承的　pthread_mutex_t对象
//到底有没有处于加锁状态。


//prepare：将在fork调用创建出子进程之前被执行，它可以给父进程中的互斥锁对象明明确确上
//	锁。这个函数是在父进程的上下文中执行的，正常使用时，我们应该在此回调函数调用　
//	pthread_mutex_lock　来给互斥锁明明确确加锁，这个时候如果父进程中的某个线程已经调用
//	pthread_mutex_lock给互斥锁加上了锁，则在此回调中调用　pthread_mutex_lock　
//	将迫使父进程中调用fork的线程处于阻塞状态，直到prepare能给互斥锁对象加锁为止。
//
//parent：　是在fork调用创建出子进程之后，而fork返回之前执行，在父进程上下文中被执行。
//	它的作用是释放所有在prepare函数中被明明确确锁住的互斥锁。
//
//child：　是在fork返回之前，在子进程上下文中被执行。和parent处理函数一样，child函数也是
//	用于释放所有在prepare函数中被明明确确锁住的互斥锁。

