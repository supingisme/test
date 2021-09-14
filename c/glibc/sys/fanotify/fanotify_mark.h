#include <sys/fanotify.h>


//fanotify(fscking all notification and file access system)
//是一个notifier，对文件系统变化产生通知的机制。
extern int fanotify_mark (int __fanotify_fd, unsigned int __flags,
			  uint64_t __mask, int __dfd, const char *__pathname);



SYSCALL_DEFINE5(fanotify_mark, int, fanotify_fd, unsigned int, flags,
                __u64, mask, int, dfd,
                const char  __user *, pathname)
{
  return do_fanotify_mark(fanotify_fd, flags, mask, dfd, pathname);
}

#ifdef CONFIG_COMPAT
COMPAT_SYSCALL_DEFINE6(fanotify_mark,
              int, fanotify_fd, unsigned int, flags,
              __u32, mask0, __u32, mask1, int, dfd,
              const char  __user *, pathname)
{
  return do_fanotify_mark(fanotify_fd, flags,
#ifdef __BIG_ENDIAN
              ((__u64)mask0 << 32) | mask1,
#else
              ((__u64)mask1 << 32) | mask0,
#endif
               dfd, pathname);
}
#endif

