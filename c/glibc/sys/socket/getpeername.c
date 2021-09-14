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
/**
 *	返回某个套接字关联的外地协议地址
 *
 *	getpeername()
 *	返回：
 *		正确：0
 *		出错：-1
 *
 *	装填由peeraddr指针所指的套接字地址结构
 *
 *
 *	16.9.4 Who is Connected to Me?
 *	int getpeername (int socket, struct sockaddr *addr, socklen t [Function]
 *	*length-ptr)
 *	The getpeername function returns the address of the socket that socket is connected
 *	to; it stores the address in the memory space specifed by addr and length-ptr. It
 *	stores the length of the address in *length-ptr.
 *	See Section 16.3 [Socket Addresses], page 391, for information about the format of
 *	the address. In some operating systems, getpeername works only for sockets in the
 *	Internet domain.
 *	The return value is 0 on success and -1 on error. The following errno error conditions
 *	are defned for this function:
 *	EBADF The argument socket is not a valid fle descriptor.
 *	ENOTSOCK The descriptor socket is not a socket.
 *	ENOTCONN The socket socket is not connected.
 *	ENOBUFS There are not enough internal buﬀers available.
 */

#include <sys/socket.h>

int getpeername(int sockfd,
				struct sockaddr *peeraddr,
				socklen_t *addrlen);
