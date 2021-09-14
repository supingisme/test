
#include <linux/aio_abi.h>          /* Defines needed types */

//io_submit - submit asynchronous I/O blocks for processing
int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocbpp);

//*** Glibc does not provide a wrapper function for this system call.   ***


/* sys_io_submit:
 *	Queue the nr iocbs pointed to by iocbpp for processing.  Returns
 *	the number of iocbs queued.  May return -EINVAL if the aio_context
 *	specified by ctx_id is invalid, if nr is < 0, if the iocb at
 *	*iocbpp[0] is not properly initialized, if the operation specified
 *	is invalid for the file descriptor in the iocb.  May fail with
 *	-EFAULT if any of the data structures point to invalid data.  May
 *	fail with -EBADF if the file descriptor specified in the first
 *	iocb is invalid.  May fail with -EAGAIN if insufficient resources
 *	are available to queue any iocbs.  Will return 0 if nr is 0.  Will
 *	fail with -ENOSYS if not implemented.
 */
SYSCALL_DEFINE3(io_submit, aio_context_t, ctx_id, long, nr,
		struct iocb __user * __user *, iocbpp)
{
	struct kioctx *ctx;
	long ret = 0;
	int i = 0;
	struct blk_plug plug;

	if (unlikely(nr < 0))
		return -EINVAL;

	ctx = lookup_ioctx(ctx_id);
	if (unlikely(!ctx)) {
		pr_debug("EINVAL: invalid context id\n");
		return -EINVAL;
	}

	if (nr > ctx->nr_events)
		nr = ctx->nr_events;

	if (nr > AIO_PLUG_THRESHOLD)
		blk_start_plug(&plug);
	for (i = 0; i < nr; i++) {
		struct iocb __user *user_iocb;

		if (unlikely(get_user(user_iocb, iocbpp + i))) {
			ret = -EFAULT;
			break;
		}

		ret = io_submit_one(ctx, user_iocb, false);
		if (ret)
			break;
	}
	if (nr > AIO_PLUG_THRESHOLD)
		blk_finish_plug(&plug);

	percpu_ref_put(&ctx->users);
	return i ? i : ret;
}

#ifdef CONFIG_COMPAT
COMPAT_SYSCALL_DEFINE3(io_submit, compat_aio_context_t, ctx_id,
		       int, nr, compat_uptr_t __user *, iocbpp)
{
	struct kioctx *ctx;
	long ret = 0;
	int i = 0;
	struct blk_plug plug;

	if (unlikely(nr < 0))
		return -EINVAL;

	ctx = lookup_ioctx(ctx_id);
	if (unlikely(!ctx)) {
		pr_debug("EINVAL: invalid context id\n");
		return -EINVAL;
	}

	if (nr > ctx->nr_events)
		nr = ctx->nr_events;

	if (nr > AIO_PLUG_THRESHOLD)
		blk_start_plug(&plug);
	for (i = 0; i < nr; i++) {
		compat_uptr_t user_iocb;

		if (unlikely(get_user(user_iocb, iocbpp + i))) {
			ret = -EFAULT;
			break;
		}

		ret = io_submit_one(ctx, compat_ptr(user_iocb), true);
		if (ret)
			break;
	}
	if (nr > AIO_PLUG_THRESHOLD)
		blk_finish_plug(&plug);

	percpu_ref_put(&ctx->users);
	return i ? i : ret;
}
#endif

