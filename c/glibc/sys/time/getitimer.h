#include <sys/time.h>

//getitimer, setitimer - get or set value of an interval timer
int getitimer(int which, struct itimerval *curr_value);
int setitimer(int which, const struct itimerval *new_value,
                struct itimerval *old_value);


/*
 * Names of the interval timers, and structure
 * defining a timer setting.
 */
#define	ITIMER_REAL	0
#define	ITIMER_VIRTUAL	1
#define	ITIMER_PROF	2

//ITIMER_REAL    decrements in real time, and delivers SIGALRM upon expiration.
//
//ITIMER_VIRTUAL decrements only when the process is executing, and delivers SIGVTALRM upon expiration.
//
//ITIMER_PROF    decrements both when the process executes and when the system is executing  on  behalf  of
//              the  process.  Coupled with ITIMER_VIRTUAL, this timer is usually used to profile the time
//              spent by the application in user and kernel space.  SIGPROF is delivered upon expiration.



SYSCALL_DEFINE2(getitimer, int, which, struct __kernel_old_itimerval __user *, value)
{
	struct itimerspec64 get_buffer;
	int error = do_getitimer(which, &get_buffer);

	if (!error && put_itimerval(value, &get_buffer))
		error = -EFAULT;
	return error;
}

#if defined(CONFIG_COMPAT) || defined(CONFIG_ALPHA)
struct old_itimerval32 {
	struct old_timeval32	it_interval;
	struct old_timeval32	it_value;
};

static int put_old_itimerval32(struct old_itimerval32 __user *o,
			       const struct itimerspec64 *i)
{
	struct old_itimerval32 v32;

	v32.it_interval.tv_sec = i->it_interval.tv_sec;
	v32.it_interval.tv_usec = i->it_interval.tv_nsec / NSEC_PER_USEC;
	v32.it_value.tv_sec = i->it_value.tv_sec;
	v32.it_value.tv_usec = i->it_value.tv_nsec / NSEC_PER_USEC;
	return copy_to_user(o, &v32, sizeof(struct old_itimerval32)) ? -EFAULT : 0;
}

COMPAT_SYSCALL_DEFINE2(getitimer, int, which,
		       struct old_itimerval32 __user *, value)
{
	struct itimerspec64 get_buffer;
	int error = do_getitimer(which, &get_buffer);

	if (!error && put_old_itimerval32(value, &get_buffer))
		error = -EFAULT;
	return error;
}
#endif

