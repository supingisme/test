//pthread_setschedparam, pthread_getschedparam - set/get scheduling policy and parameters of a thread
//
//SYNOPSIS
#include <pthread.h>

/* Functions for scheduling control.  */

/* Set the scheduling parameters for TARGET_THREAD according to POLICY
   and *PARAM.  */
extern int pthread_setschedparam(pthread_t __target_thread, int __policy,
				  const struct sched_param *__param);

/* Return in *POLICY and *PARAM the scheduling parameters for TARGET_THREAD. */
extern int pthread_getschedparam(pthread_t __target_thread,
				  int * __policy,
				  struct sched_param * __param);

//Compile and link with -pthread.


