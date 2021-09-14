//pthread_setaffinity_np, pthread_getaffinity_np - set/get CPU affinity of a thread
//
//SYNOPSIS
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>

//int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize,
//                          const cpu_set_t *cpuset);
int pthread_getaffinity_np(pthread_t thread, size_t cpusetsize,
                          cpu_set_t *cpuset);

//Compile and link with -pthread.


