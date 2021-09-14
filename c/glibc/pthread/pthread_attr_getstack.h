//pthread_attr_setstack, pthread_attr_getstack - set/get stack attributes in thread attributes object
//
//SYNOPSIS
#include <pthread.h>

int pthread_attr_setstack(pthread_attr_t *attr,
                         void *stackaddr, size_t stacksize);
int pthread_attr_getstack(pthread_attr_t *attr,
                         void **stackaddr, size_t *stacksize);

//Compile and link with -pthread.

