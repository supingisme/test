#include <linux/aio_abi.h>         /* Defines needed types */
#include <linux/time.h>            /* Defines 'struct timespec' */


int io_getevents(aio_context_t ctx_id, long min_nr, long nr,
                struct io_event *events, struct timespec *timeout);
//*** Glibc does not provide a wrapper function for this system call.   ***



/* io_getevents:
 *  Attempts to read at least min_nr events and up to nr events from
 *  the completion queue for the aio_context specified by ctx_id. If
 *  it succeeds, the number of read events is returned. May fail with
 *  -EINVAL if ctx_id is invalid, if min_nr is out of range, if nr is
 *  out of range, if timeout is out of range.  May fail with -EFAULT
 *  if any of the memory specified is invalid.  May return 0 or
 *  < min_nr if the timeout specified by timeout has elapsed
 *  before sufficient events are available, where timeout == NULL
 *  specifies an infinite timeout. Note that the timeout pointed to by
 *  timeout is relative.  Will fail with -ENOSYS if not implemented.
 */
#ifdef CONFIG_64BIT

SYSCALL_DEFINE5(io_getevents, aio_context_t, ctx_id,
        long, min_nr,
        long, nr,
        struct io_event __user *, events,
        struct __kernel_timespec __user *, timeout)
{
    struct timespec64   ts;
    int         ret;

    if (timeout && unlikely(get_timespec64(&ts, timeout)))
        return -EFAULT;

    ret = do_io_getevents(ctx_id, min_nr, nr, events, timeout ? &ts : NULL);
    if (!ret && signal_pending(current))
        ret = -EINTR;
    return ret;
}

#endif

SYSCALL_DEFINE6(io_pgetevents,
		aio_context_t, ctx_id,
		long, min_nr,
		long, nr,
		struct io_event __user *, events,
		struct __kernel_timespec __user *, timeout,
		const struct __aio_sigset __user *, usig)
{
	struct __aio_sigset	ksig = { NULL, };
	struct timespec64	ts;
	bool interrupted;
	int ret;

	if (timeout && unlikely(get_timespec64(&ts, timeout)))
		return -EFAULT;

	if (usig && copy_from_user(&ksig, usig, sizeof(ksig)))
		return -EFAULT;

	ret = set_user_sigmask(ksig.sigmask, ksig.sigsetsize);
	if (ret)
		return ret;

	ret = do_io_getevents(ctx_id, min_nr, nr, events, timeout ? &ts : NULL);

	interrupted = signal_pending(current);
	restore_saved_sigmask_unless(interrupted);
	if (interrupted && !ret)
		ret = -ERESTARTNOHAND;

	return ret;
}

