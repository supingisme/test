//pthread_getattr_np - get attributes of created thread
//
//SYNOPSIS
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <pthread.h>

int pthread_getattr_np(pthread_t thread, pthread_attr_t *attr);

//Compile and link with -pthread.

