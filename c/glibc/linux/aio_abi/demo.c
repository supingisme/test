#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>
//#include <libaio.h>
#include <sys/stat.h>

#include <linux/aio_abi.h>          /* Defines needed types */


/*
gcc io_submit.c -laio

*/


int main()
{
    unsigned nr_events = 10;
    aio_context_t ctx_idp;
//    struct iocb _iocb[1];
    
    memset(ctx_idp, 0, sizeof(aio_context_t));

    int ret;
    int fd;
    char *buf;
    
    ret = io_setup(nr_events, &ctx_idp);
    printf("io_setup ret = %d, ctx_idp = %ld\n", ret, ctx_idp);

    fd = open("./direct.txt", O_CREAT|O_DIRECT|O_WRONLY, S_IRWXU|S_IRWXG|S_IRWXO);
    printf("Open fd = %d\n", fd);

    ret = posix_memalign(&buf, sysconf(_SC_PAGESIZE), sysconf(_SC_PAGESIZE));
    printf("posix_memalign ret = %d\n", ret);

    strcpy(buf, "RTOAX >>>>>>>>>>>>>>>>>>>>>> RTOAX");

    struct iocb *iocbpp = (struct iocb*)malloc(sizeof(struct iocb));
    memset(iocbpp, 0, sizeof(struct iocb));

    iocbpp[0].aio_data = buf;
    iocbpp[0].aio_lio_opcode = IO_CMD_PWRITE;
    iocbpp[0].aio_reqprio = 0;
    iocbpp[0].aio_fildes = fd;

    iocbpp[0].aio_buf = buf;
    iocbpp[0].aio_nbytes = sysconf(_SC_PAGESIZE);
    iocbpp[0].aio_offset = 0;


    ret = io_submit(ctx_idp, 1, iocbpp);
    printf("io_submit ret = %d, ctx_idp = %ld\n", ret, ctx_idp);

    ret = io_destroy(ctx_idp);
    printf("io_destroy ret = %d, ctx_idp = %ld\n", ret, ctx_idp);
}




