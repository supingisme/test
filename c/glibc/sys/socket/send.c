/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:29 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/*
 *	16.9.5.1 Sending Data
 *	The send function is declared in the header fle ‘sys/socket.h’. If your ﬂags argument is
 *	zero, you can just as well use write instead of send; see Section 13.2 [Input and Output
 *	Primitives], page 299. If the socket was connected but the connection has broken, you get
 *	a SIGPIPE signal for any use of send or write (see Section 24.2.7 [Miscellaneous Signals],
 *	page 611).
 *	int send (int socket, void *buffer, size t size, int flags) [Function]
 *	The send function is like write, but with the additional ﬂags ﬂags. The possible
 *	values of ﬂags are described in Section 16.9.5.3 [Socket Data Options], page 418.
 *	This function returns the number of bytes transmitted, or -1 on failure. If the socket
 *	is nonblocking, then send (like write) can return after sending just part of the data.
 *	See Section 13.14 [File Status Flags], page 333, for information about nonblocking
 *	mode.
 *	Note, however, that a successful return value merely indicates that the message has
 *	been sent without error, not necessarily that it has been received without error.
 *	The following errno error conditions are defned for this function:
 *	EBADF The socket argument is not a valid fle descriptor.
 *	EINTR The operation was interrupted by a signal before any data was sent. See
 *	Section 24.5 [Primitives Interrupted by Signals], page 628.
 *	ENOTSOCK The descriptor socket is not a socket.
 *	EMSGSIZE The socket type requires that the message be sent atomically, but the
 *	message is too large for this to be possible.
 *	EWOULDBLOCK
 *	Nonblocking mode has been set on the socket, and the write operation
 *	would block. (Normally send blocks until the operation can be com
 *	pleted.)
 *	ENOBUFS There is not enough internal buﬀer space available.
 *	ENOTCONN You never connected this socket.
 *	EPIPE This socket was connected but the connection is now broken. In this case,
 *	send generates a SIGPIPE signal frst; if that signal is ignored or blocked,
 *	or if its handler returns, then send fails with EPIPE.
 *	This function is defned as a cancellation point in multi-threaded programs, so one
 *	has to be prepared for this and make sure that allocated resources (like memory, fles
 *	descriptors, semaphores or whatever) are freed even if the thread is canceled.
 */
#include <sys/socket.h>

int send (int socket, void *buffer, size_t size, int flags);

/** flags
 *
 *	MSG_DONTROUTE
 *	This flag tells the kernel that the destination is on a locally attached network and not to perform a lookup of the routing table. We provided additional information on this feature with the SO_DONTROUTE socket option (Section 7.5(See 8.5.5)). This feature can be enabled for a single output operation with the MSG_DONTROUTE flag, or enabled for all output operations for a given socket using the socket option.
 *	MSG_DONTWAIT
 *	This flag specifies nonblocking for a single I/O operation, without having to turn on the nonblocking flag for the socket, perform the I/O operation, and then turn off the nonblocking flag. We will describe nonblocking I/O in Chapter 16(See 9.5), along with turning the nonblocking flag on and off for all I/O operations on a socket.
 *	This flag is newer than the others and might not be supported on all systems.
 *	MSG_OOB
 *	With send, this flag specifies that out-of-band data is being sent. With TCP, only one byte should be sent as out-of-band data, as we will describe in Chapter 24(See 9.13). With recv, this flag specifies that out-of-band data is to be read instead of normal data.
 *	MSG_PEEK
 *	This flag lets us look at the data that is available to be read, without having the system discard the data after the recv or recvfrom returns. We will talk more about this in Section 14.7(See 9.3.7).
 *	MSG_WAITALL
 *	This flag was introduced with 4.3BSD Reno. It tells the kernel not to return from a read operation until the requested number of bytes have been read. If the system supports this flag, we can then omit the readn function (Figure 3.15(See 8.1.9)) and replace it with the following macro:
 *
 *	MSG_DONTROUTE
 *	This flag tells the kernel that the destination is on a locally attached network and not to perform a lookup of the routing table. We provided additional information on this feature with the SO_DONTROUTE socket option (Section 7.5(See 8.5.5)). This feature can be enabled for a single output operation with the MSG_DONTROUTE flag, or enabled for all output operations for a given socket using the socket option.
 */
