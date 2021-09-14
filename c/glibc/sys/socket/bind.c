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
/*	16.3.2 Setting the Address of a Socket
 *	Use the bind function to assign an address to a socket. The prototype for bind is in the
 *	header fle ‘sys/socket.h’. For examples of use, see Section 16.5.3 [Example of Local
 *	Namespace Sockets], page 396, or see Section 16.6.7 [Internet Socket Example], page 410.
 *	int bind (int socket, struct sockaddr *addr, socklen t length) [Function]
 *	The bind function assigns an address to the socket socket. The addr and length
 *	arguments specify the address; the detailed format of the address depends on the
 *	namespace. The frst part of the address is always the format designator, which
 *	specifes a namespace, and says that the address is in the format of that namespace.
 *	The return value is 0 on success and -1 on failure. The following errno error condi
 *	tions are defned for this function:
 *	EBADF The socket argument is not a valid fle descriptor.
 *	ENOTSOCK The descriptor socket is not a socket.
 *	EADDRNOTAVAIL
 *	The specifed address is not available on this machine.
 *	EADDRINUSE
 *	Some other socket is already using the specifed address.
 *	EINVAL The socket socket already has an address.
 *	EACCES You do not have permission to access the requested address. (In the
 *	Internet domain, only the super-user is allowed to specify a port number
 *	in the range 0 through IPPORT_RESERVED minus one; see Section 16.6.3
 *	[Internet Ports], page 406.)
 *	Additional conditions may be possible depending on the particular namespace of the
 *	socket.
 */
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	struct sockaddr	addr;
	addr.sa_family = AF_LOCAL;

	bind(1, &addr, sizeof(struct sockaddr));
	perror("bind");
	//bind();
	return 0;
}
