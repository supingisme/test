#include <sched.h>

//get the SCHED_RR interval for the named process
int sched_rr_get_interval(pid_t pid, struct timespec * tp);




/**
 * sys_sched_rr_get_interval - return the default timeslice of a process.
 * @pid: pid of the process.
 * @interval: userspace pointer to the timeslice value.
 *
 * this syscall writes the default timeslice value of a given process
 * into the user-space timespec buffer. A value of '0' means infinity.
 *
 * Return: On success, 0 and the timeslice is in @interval. Otherwise,
 * an error code.
 */
SYSCALL_DEFINE2(sched_rr_get_interval, pid_t, pid,
		struct __kernel_timespec __user *, interval)
{
	struct timespec64 t;
	int retval = sched_rr_get_interval(pid, &t);

	if (retval == 0)
		retval = put_timespec64(&t, interval);

	return retval;
}
        
#ifdef CONFIG_COMPAT_32BIT_TIME
SYSCALL_DEFINE2(sched_rr_get_interval_time32, pid_t, pid,
        struct old_timespec32 __user *, interval)
{
    struct timespec64 t;
    int retval = sched_rr_get_interval(pid, &t);

    if (retval == 0)
        retval = put_old_timespec32(&t, interval);
    return retval;
}
#endif

