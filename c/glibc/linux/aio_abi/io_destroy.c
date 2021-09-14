#include <linux/aio_abi.h>          /* Defines needed types */
#include <errno.h>
#include <stdio.h>

//int io_setup(unsigned nr_events, aio_context_t *ctx_idp);

/*
gcc io_setup.c -laio

*/



int main()
{
    unsigned nr_events = 1;
    aio_context_t ctx_idp;
    
    ctx_idp =0;

    int ret = io_setup(nr_events, &ctx_idp);

    switch(-ret) {
        case EAGAIN:// The  specified  nr_events  exceeds  the  user's  limit  of  available  events,   
                    //as   defined   in  /proc/sys/fs/aio-max-nr.
            printf("The  specified  nr_events  exceeds  the  user's  limit  of  available  events, "\
                    "as   defined   in  /proc/sys/fs/aio-max-nr.\n");
            break;
        case EFAULT:// An invalid pointer is passed for ctx_idp.
            printf("An invalid pointer is passed for ctx_idp.\n");
            break;

        case EINVAL:// ctx_idp  is not initialized, or the specified nr_events exceeds internal limits.  nr_events should
                    //be greater than 0.
            printf("ctx_idp  is not initialized, or the specified nr_events exceeds internal limits.  "\
                    "nr_events should be greater than 0.\n");
            break;

        case ENOMEM:// Insufficient kernel resources are available.
            printf("Insufficient kernel resources are available.\n");
            break;

        case ENOSYS:// io_setup() is not implemented on this architecture.:
            printf("io_setup() is not implemented on this architecture.:\n");
            break;
    }

    printf("io_setup ret = %d, ctx_idp = %ld\n", ret, ctx_idp);

    ret = io_destroy(ctx_idp);
    printf("io_destroy ret = %d, ctx_idp = %ld\n", ret, ctx_idp);
}

