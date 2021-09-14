
//pthread_attr_setaffinity_np,  pthread_attr_getaffinity_np  -  set/get  CPU  affinity  attribute in thread
//attributes object
//
//SYNOPSIS
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>

int pthread_attr_setaffinity_np(pthread_attr_t *attr,
                            size_t cpusetsize, const cpu_set_t *cpuset);
int pthread_attr_getaffinity_np(pthread_attr_t *attr,
                            size_t cpusetsize, cpu_set_t *cpuset);

//Compile and link with -pthread.

