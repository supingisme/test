//pthread_attr_setschedparam,  pthread_attr_getschedparam  -  set/get  scheduling  parameter  attributes in
//thread attributes object
//
//SYNOPSIS
#include <pthread.h>

struct sched_param {
   int sched_priority;     /* Scheduling priority */
};

SCHED_OTHER   the standard round-robin time-sharing policy;

SCHED_BATCH   for "batch" style execution of processes; and

SCHED_IDLE    for running very low priority background jobs.

The following "real-time" policies are also supported, for special time-critical applications  that  need
precise control over the way in which runnable processes are selected for execution:

SCHED_FIFO    a first-in, first-out policy; and

SCHED_RR      a round-robin policy.

int pthread_attr_setschedparam(pthread_attr_t *attr,
                                const struct sched_param *param);
//int pthread_attr_getschedparam(pthread_attr_t *attr,
//                                    struct sched_param *param);

//Compile and link with -pthread.
//RETURN VALUE
//On success, these functions return 0; on error, they return a nonzero error number.


