//pthread_setname_np, pthread_getname_np - set/get the name of a thread
//
//SYNOPSIS
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>
int pthread_setname_np(pthread_t thread, const char *name);
int pthread_getname_np(pthread_t thread,
                      const char *name, size_t len);

//Compile and link with -pthread.

