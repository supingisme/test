#include <linux/aio_abi.h>          /* Defines needed types */
#include <errno.h>
#include <stdio.h>

/*
gcc io_submit.c -laio

*/


int main()
{
    unsigned nr_events = 1;
    aio_context_t ctx_idp;
    struct iocb _iocb[1];
    
    ctx_idp =0;

    int ret;
    
    ret = io_setup(nr_events, &ctx_idp);
    printf("io_setup ret = %d, ctx_idp = %ld\n", ret, ctx_idp);

    ret = io_submit(ctx_idp, 1, &_iocb);
    printf("io_submit ret = %d, ctx_idp = %ld\n", ret, ctx_idp);
    switch(-ret) {
        case EAGAIN:// Insufficient resources are available to queue any iocbs.
            printf("Insufficient resources are available to queue any iocbs.\n");
            break;
        case EBADF://  The file descriptor specified in the first iocb is invalid.
            printf("The file descriptor specified in the first iocb is invalid.\n");
            break;

        case EFAULT:// One of the data structures points to invalid data.
            printf("One of the data structures points to invalid data.\n");
            break;

        case EINVAL:// The AIO context specified by ctx_id is invalid.  nr is less than 0.  The iocb at *iocbpp[0] is not
              //://properly initialized, or the operation specified is invalid for the file descriptor in the iocb.
            
            printf("The AIO context specified by ctx_id is invalid.  nr is less than 0. \n");
            break;
        case ENOSYS:// io_submit() is not implemented on this architecture.
            printf("io_submit() is not implemented on this architecture.\n");
            break;
    }

    ret = io_destroy(ctx_idp);
    printf("io_destroy ret = %d, ctx_idp = %ld\n", ret, ctx_idp);
}



