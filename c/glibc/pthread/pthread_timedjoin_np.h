#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>

//try to join with a terminated thread
//int pthread_tryjoin_np(pthread_t thread, void **retval);

int pthread_timedjoin_np(pthread_t thread, void **retval,
                        const struct timespec *abstime);

//Compile and link with -pthread.


