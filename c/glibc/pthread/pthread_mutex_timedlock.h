#include <pthread.h>
#include <time.h>

//lock a mutex (ADVANCED REALTIME)
int pthread_mutex_timedlock(pthread_mutex_t * mutex,
                                const struct timespec * abs_timeout);
