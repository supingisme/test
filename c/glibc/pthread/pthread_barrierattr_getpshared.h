#include <pthread.h>

//get and set the process-shared attribute of the barrier attributes object (ADVANCED REALTIME THREADS)
int pthread_barrierattr_getpshared(const pthread_barrierattr_t *attr, int *pshared);
int pthread_barrierattr_setpshared(pthread_barrierattr_t *attr, int pshared);

