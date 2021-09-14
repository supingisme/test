/**
 *	互斥锁：上锁和解锁
 */

#include <pthread.h>

int pthread_mutex_lock(pthread_mutex_t *mptr);
/**
 *	pthread-mutex-t rylock is a nonblocking function that returns EBUSY if the mutex
 *	is already locked.
 */
int pthread_mutex_trylock(pthread_mutex_t *mptr);
int pthread_mutex_unlock(pthread_mutex_t *mptr);

/**
 *	如果尝试给一个已由另外一个线程锁住的互斥锁上锁，那么pthread_mutex_lock将
 *	阻塞到该互斥锁解锁为止。pthread_mutex_trylock是对应的非阻塞函数，如果该
 *	互斥锁已锁住，它就返回一个EBUSY错误。
 */


