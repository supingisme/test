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
 *	16.10.2 Receiving Datagrams
 *	The recvfrom function reads a packet from a datagram socket and also tells you where it
 *	was sent from. This function is declared in ‘sys/socket.h’.
 *	int recvfrom (int socket, void *buffer, size t size, int flags, struct [Function]
 *	sockaddr *addr, socklen t *length-ptr)
 *	The recvfrom function reads one packet from the socket socket into the buﬀer buﬀer.
 *	The size argument specifes the maximum number of bytes to be read.
 *	If the packet is longer than size bytes, then you get the frst size bytes of the packet
 *	and the rest of the packet is lost. There’s no way to read the rest of the packet. Thus,
 *	when you use a packet protocol, you must always know how long a packet to expect.
 *	The addr and length-ptr arguments are used to return the address where the packet
 *	came from. See Section 16.3 [Socket Addresses], page 391. For a socket in the local
 *	domain the address information won’t be meaningful, since you can’t read the address
 *	of such a socket (see Section 16.5 [The Local Namespace], page 395). You can specify
 *	a null pointer as the addr argument if you are not interested in this information.
 *	The ﬂags are interpreted the same way as for recv (see Section 16.9.5.3 [Socket Data
 *	Options], page 418). The return value and error conditions are also the same as for
 *	recv.
 *	This function is defned as a cancellation point in multi-threaded programs, so one
 *	has to be prepared for this and make sure that allocated resources (like memory, fles
 *	descriptors, semaphores or whatever) are freed even if the thread is canceled.
 *
 *
 *	You can use plain recv (see Section 16.9.5.2 [Receiving Data], page 417) instead of
 *	recvfrom if you don’t need to fnd out who sent the packet (either because you know where
 *	it should come from or because you treat all possible senders alike). Even read can be used
 *	if you don’t want to specify ﬂags (see Section 13.2 [Input and Output Primitives], page 299).
 */
#include <sys/socket.h>

int recvfrom(int sockfd, void *buf, size_t size, int flags, struct sockaddr *addr,
			socklen_t *plength);
