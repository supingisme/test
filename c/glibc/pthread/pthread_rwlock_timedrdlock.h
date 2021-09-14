#include <pthread.h>
#include <time.h>

//lock a read-write lock for reading
int pthread_rwlock_timedrdlock(pthread_rwlock_t *rwlock, const struct timespec *abs_timeout);

