
/* Asynchronous I/O control block.  */
struct aiocb
{
  int aio_fildes;		/* File desriptor.  */
  int aio_lio_opcode;		/* Operation to be performed.  */
  int aio_reqprio;		/* Request priority offset.  */
  volatile void *aio_buf;	/* Location of buffer.  */
  size_t aio_nbytes;		/* Length of transfer.  */
  struct sigevent aio_sigevent;	/* Signal number and value.  */

  /* Internal members.  */
  struct aiocb *__next_prio;
  int __abs_prio;
  int __policy;
  int __error_code;
  __ssize_t __return_value;

#ifndef __USE_FILE_OFFSET64
  __off_t aio_offset;		/* File offset.  */
  char __pad[sizeof (__off64_t) - sizeof (__off_t)];
#else
  __off64_t aio_offset;		/* File offset.  */
#endif
  char __unused[32];
};

