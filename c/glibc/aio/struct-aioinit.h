#ifdef __USE_GNU
/* To customize the implementation one can use the following struct.
   This implementation follows the one in Irix.  */
struct aioinit
  {
    int aio_threads;		/* Maximal number of threads.  */
    int aio_num;		/* Number of expected simultanious requests. */
    int aio_locks;		/* Not used.  */
    int aio_usedba;		/* Not used.  */
    int aio_debug;		/* Not used.  */
    int aio_numusers;		/* Not used.  */
    int aio_idle_time;		/* Number of seconds before idle thread
				   terminates.  */
    int aio_reserved;
  };
#endif
