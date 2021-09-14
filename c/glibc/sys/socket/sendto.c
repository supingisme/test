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
 *	数据报
 *
 *	16.10.1 Sending Datagrams
 *	The normal way of sending data on a datagram socket is by using the sendto function,
 *	declared in ‘sys/socket.h’.
 *	You can call connect on a datagram socket, but this only specifes a default destination
 *	for further data transmission on the socket. When a socket has a default destination you can
 *	use send (see Section 16.9.5.1 [Sending Data], page 417) or even write (see Section 13.2
 *
 *	[Input and Output Primitives], page 299) to send a packet there. You can cancel the
 *	default destination by calling connect using an address format of AF_UNSPEC in the addr
 *	argument. See Section 16.9.1 [Making a Connection], page 413, for more information about
 *	the connect function.
 *	int sendto (int socket, void *buffer. size t size, int flags, struct [Function]
 *	sockaddr *addr, socklen t length)
 *	The sendto function transmits the data in the buﬀer through the socket socket to the
 *	destination address specifed by the addr and length arguments. The size argument
 *	specifes the number of bytes to be transmitted.
 *	The ﬂags are interpreted the same way as for send; see Section 16.9.5.3 [Socket Data
 *	Options], page 418.
 *	The return value and error conditions are also the same as for send, but you cannot
 *	rely on the system to detect errors and report them; the most common error is that
 *	the packet is lost or there is no-one at the specifed address to receive it, and the
 *	operating system on your machine usually does not know this.
 *	It is also possible for one call to sendto to report an error owing to a problem related
 *	to a previous call.
 *	This function is defned as a cancellation point in multi-threaded programs, so one
 *	has to be prepared for this and make sure that allocated resources (like memory, fles
 *	descriptors, semaphores or whatever) are freed even if the thread is canceled.
 *
 */
#include <sys/socket.h>

int sendto (int socket, void *buffer. size t size, int flags, 
		struct sockaddr *addr, socklen t length);
