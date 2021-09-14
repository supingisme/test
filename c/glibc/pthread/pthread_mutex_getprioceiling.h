#include <pthread.h>

//get and set the priority ceiling of a mutex(REALTIME THREADS)
//获取MUTEX的优先级上限。
int pthread_mutex_getprioceiling(const pthread_mutex_t * mutex,
                                int * prioceiling);
int pthread_mutex_setprioceiling(pthread_mutex_t * mutex,
                                int prioceiling, int * old_ceiling);

