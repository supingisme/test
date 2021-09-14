/**
 *  libaio: test/c/glibc/libaio
 *  
 *  aio.h: test/c/glibc/aio
 *  
 *  aio_abi.h: test/c/glibc/linux/aio_abi
 *              *** Glibc does not provide a wrapper function for this system call.   ***
 *  
 *  RToax   2020年10月30日
 */



//libaio: test/c/glibc/libaio
/**
 *  查看本仓库目录 test/c/glibc/libaio
 *  
 */
//----------------------------------------------------------------------------------------------------------------------
/* library wrappers */
extern int io_queue_init(int maxevents, io_context_t *ctxp);
/*extern int io_queue_grow(io_context_t ctx, int new_maxevents);*/
extern int io_queue_release(io_context_t ctx);
/*extern int io_queue_wait(io_context_t ctx, struct timespec *timeout);*/
extern int io_queue_run(io_context_t ctx);

/* Actual syscalls */
extern int io_setup(int maxevents, io_context_t *ctxp);
extern int io_destroy(io_context_t ctx);
extern int io_submit(io_context_t ctx, long nr, struct iocb *ios[]);
extern int io_cancel(io_context_t ctx, struct iocb *iocb, struct io_event *evt);
extern int io_getevents(io_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct timespec *timeout);

static inline void io_set_callback(struct iocb *iocb, io_callback_t cb);
static inline void io_prep_pread(struct iocb *iocb, int fd, void *buf, size_t count, long long offset);
static inline void io_prep_pwrite(struct iocb *iocb, int fd, void *buf, size_t count, long long offset);
static inline void io_prep_preadv(struct iocb *iocb, int fd, const struct iovec *iov, int iovcnt, long long offset);
static inline void io_prep_pwritev(struct iocb *iocb, int fd, const struct iovec *iov, int iovcnt, long long offset);
/* Jeff Moyer says this was implemented in Red Hat AS2.1 and RHEL3.
* AFAICT, it was never in mainline, and should not be used. --RR */
static inline void io_prep_poll(struct iocb *iocb, int fd, int events);
static inline int io_poll(io_context_t ctx, struct iocb *iocb, io_callback_t cb, int fd, int events);
static inline void io_prep_fsync(struct iocb *iocb, int fd);
static inline int io_fsync(io_context_t ctx, struct iocb *iocb, io_callback_t cb, int fd);
static inline void io_prep_fdsync(struct iocb *iocb, int fd);
static inline int io_fdsync(io_context_t ctx, struct iocb *iocb, io_callback_t cb, int fd);
static inline void io_set_eventfd(struct iocb *iocb, int eventfd);


//aio.h: test/c/glibc/aio
/**
 *  查看本仓库目录 test/c/glibc/aio
 *  
 */
//----------------------------------------------------------------------------------------------------------------------
int aio_cancel(int fd, struct aiocb *aiocbp);
int aio_error(const struct aiocb *aiocbp);
int aio_fsync(int op, struct aiocb *aiocbp);
int aio_read(struct aiocb *aiocbp); 
int aio_write(struct aiocb *aiocbp);
int lio_listio(int mode, struct aiocb *const aiocb_list[], int nitems, struct sigevent *sevp);
int aio_suspend(const struct aiocb * const aiocb_list[], int nitems, const struct timespec *timeout);
ssize_t aio_return(struct aiocb *aiocbp);



//aio_abi.h: test/c/glibc/linux/aio_abi
//----------------------------------------------------------------------------------------------------------------------
/**
 *  查看本仓库目录 test/c/glibc/linux/aio_abi
 *  
 *  *** Glibc does not provide a wrapper function for this system call.   ***
 */
int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocbpp);
int io_setup(unsigned nr_events, aio_context_t *ctx_idp);
int io_getevents(aio_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct timespec *timeout);
int io_cancel(aio_context_t ctx_id, struct iocb *iocb, struct io_event *result);
int io_destroy(aio_context_t ctx_id);



