#include <poll.h>

/* Event types that can be polled for.  These bits may be set in `events'
   to indicate the interesting event types; they will appear in `revents'
   to indicate the status of the file descriptor.  */
#define POLLIN		0x001		/* There is data to read.  */
#define POLLPRI		0x002		/* There is urgent data to read.  */
#define POLLOUT		0x004		/* Writing now will not block.  */


#if defined __USE_XOPEN || defined __USE_XOPEN2K8
/* These values are defined in XPG4.2.  */
# define POLLRDNORM	0x040		/* Normal data may be read.  */
# define POLLRDBAND	0x080		/* Priority data may be read.  */
# define POLLWRNORM	0x100		/* Writing now will not block.  */
# define POLLWRBAND	0x200		/* Priority data may be written.  */
#endif

#ifdef __USE_GNU
/* These are extensions for Linux.  */
# define POLLMSG	0x400
# define POLLREMOVE	0x1000
# define POLLRDHUP	0x2000
#endif

/* Event types always implicitly polled for.  These bits need not be set in
   `events', but they will appear in `revents' to indicate the status of
   the file descriptor.  */
#define POLLERR		0x008		/* Error condition.  */
#define POLLHUP		0x010		/* Hung up.  */
#define POLLNVAL	0x020		/* Invalid polling request.  */

/**
  POLLIN        普通或优先级带数据可读
  POLLRDNORM    普通数据可读
  POLLRDBAND    优先级带数据可读
  POLLPRI       高优先级数据可读
  
  POLLOUT       普通数据可写
  POLLWRNORM    普通数据可写
  POLLWRBAND    优先级带数据可写
  
  POLLERR       发生错误
  POLLHUP       发生挂起
  POLLNVAL      描述符不是一个可打开的文件

 */


struct pollfd {
   int   fd;         /* file descriptor */
   short events;     /* requested events */
   short revents;    /* returned events */
};

