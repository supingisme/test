//pthread_setaffinity_np, pthread_getaffinity_np - set/get CPU affinity of a thread
//
//SYNOPSIS
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>

int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize,
                          const cpu_set_t *cpuset);
//int pthread_getaffinity_np(pthread_t thread, size_t cpusetsize,
//                          cpu_set_t *cpuset);

//Compile and link with -pthread.
void CPU_ZERO(cpu_set_t  *set);//(初始化操作)
void CPU_SET(int cpu,cpu_set_t *set);//(将某个cpu加进cpu集里)
void CPU_CLR(int cpu,cpu_set_t *set);//(将某个cpu清除出cpu集里)
void CPU_ISSET(int cpu,const cpu_set_t *set);//(判断某个cpu是不是在cpu集里)

