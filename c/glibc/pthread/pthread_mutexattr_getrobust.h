#include <pthread.h>

/* Robust mutex or not flags.  */
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};


//get and set the mutex robust attribute
//获取并设置互斥健壮属性
//锁的拥有者死掉后，其他线程试图获取锁将直接返回 EOWNERDEAD
int pthread_mutexattr_getrobust(const pthread_mutexattr_t *attr, int * robust);
int pthread_mutexattr_setrobust(pthread_mutexattr_t *attr, int robust);

