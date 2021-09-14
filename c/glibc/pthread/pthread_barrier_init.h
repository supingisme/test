#include <pthread.h>

//destroy and initialize a barrier object (ADVANCED REAL‐TIME THREADS)
int pthread_barrier_destroy(pthread_barrier_t *barrier);
int pthread_barrier_init(pthread_barrier_t * barrier, const pthread_barrierattr_t *attr, unsigned count);

