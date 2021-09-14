#include <pthread.h>

/* Process shared or private flag.  */
enum
{
  PTHREAD_PROCESS_PRIVATE,
#define PTHREAD_PROCESS_PRIVATE PTHREAD_PROCESS_PRIVATE
  PTHREAD_PROCESS_SHARED
#define PTHREAD_PROCESS_SHARED  PTHREAD_PROCESS_SHARED
};



//get and set the process-shared attribute of the read-write lock attributes object
int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t * attr, int * pshared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr, int pshared);

