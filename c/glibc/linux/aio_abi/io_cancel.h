#include <linux/aio_abi.h>          /* Defines needed types */

//cancel an outstanding asynchronous I/O operation
int io_cancel(aio_context_t ctx_id, struct iocb *iocb,
                    struct io_event *result);

//*** Glibc does not provide a wrapper function for this system call.   ***


/* sys_io_cancel:
 *  Attempts to cancel an iocb previously passed to io_submit.  If
 *  the operation is successfully cancelled, the resulting event is
 *  copied into the memory pointed to by result without being placed
 *  into the completion queue and 0 is returned.  May fail with
 *  -EFAULT if any of the data structures pointed to are invalid.
 *  May fail with -EINVAL if aio_context specified by ctx_id is
 *  invalid.  May fail with -EAGAIN if the iocb specified was not
 *  cancelled.  Will fail with -ENOSYS if not implemented.
 */
SYSCALL_DEFINE3(io_cancel, aio_context_t, ctx_id, struct iocb __user *, iocb,
        struct io_event __user *, result)
{
    struct kioctx *ctx;
    struct aio_kiocb *kiocb;
    int ret = -EINVAL;
    u32 key;
    u64 obj = (u64)(unsigned long)iocb;

    if (unlikely(get_user(key, &iocb->aio_key)))
        return -EFAULT;
    if (unlikely(key != KIOCB_KEY))
        return -EINVAL;

    ctx = lookup_ioctx(ctx_id);
    if (unlikely(!ctx))
        return -EINVAL;

    spin_lock_irq(&ctx->ctx_lock);
    /* TODO: use a hash or array, this sucks. */
    list_for_each_entry(kiocb, &ctx->active_reqs, ki_list) {
        if (kiocb->ki_res.obj == obj) {
            ret = kiocb->ki_cancel(&kiocb->rw);
            list_del_init(&kiocb->ki_list);
            break;
        }
    }
    spin_unlock_irq(&ctx->ctx_lock);

    if (!ret) {
        /*
         * The result argument is no longer used - the io_event is
         * always delivered via the ring buffer. -EINPROGRESS indicates
         * cancellation is progress:
         */
        ret = -EINPROGRESS;
    }

    percpu_ref_put(&ctx->users);

    return ret;
}

