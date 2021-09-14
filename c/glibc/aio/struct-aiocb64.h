/* The same for the 64bit offsets.  Please note that the members aio_fildes
   to __return_value have to be the same in aiocb and aiocb64.  */
#ifdef __USE_LARGEFILE64
struct aiocb64
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

  __off64_t aio_offset;		/* File offset.  */
  char __unused[32];
};
#endif

