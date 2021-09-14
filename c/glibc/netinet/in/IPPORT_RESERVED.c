/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:18 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:27 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 08:57:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:57:39 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:52:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/*
 *	16.6.3 Internet Ports
 *	A socket address in the Internet namespace consists of a machine’s Internet address plus
 *	a port number which distinguishes the sockets on a given machine (for a given protocol).
 *	Port numbers range from 0 to 65,535.
 *	Port numbers less than IPPORT_RESERVED are reserved for standard servers, such as
 *	finger and telnet. There is a database that keeps track of these, and you can use the
 *	getservbyname function to map a service name onto a port number; see Section 16.6.4 [The
 *	Services Database], page 406.
 *	If you write a server that is not one of the standard ones defned in the database, you
 *	must choose a port number for it. Use a number greater than IPPORT_USERRESERVED; such
 *	numbers are reserved for servers and won’t ever be generated automatically by the system.
 *	Avoiding conﬂicts with servers being run by other users is up to you.
 *	When you use a socket without specifying its address, the system generates a port
 *	number for it. This number is between IPPORT_RESERVED and IPPORT_USERRESERVED.
 *	On the Internet, it is actually legitimate to have two diﬀerent sockets with the same
 *	port number, as long as they never both try to communicate with the same socket address
 *	(host address plus port number). You shouldn’t duplicate a port number except in special
 *	circumstances where a higher-level protocol requires it. Normally, the system won’t let you
 *	do it; bind normally insists on distinct port numbers. To reuse a port number, you must
 *	set the socket option SO_REUSEADDR. See Section 16.12.2 [Socket-Level Options], page 430.
 *	These macros are defned in the header fle ‘netinet/in.h’.
 *	int IPPORT_RESERVED [Macro]
 *	Port numbers less than IPPORT_RESERVED are reserved for superuser use.
 *	int IPPORT_USERRESERVED [Macro]
 *	Port numbers greater than or equal to IPPORT_USERRESERVED are reserved for explicit
 *	use; they will never be allocated automatically.
 */
#include <netinet/in.h>
#include <stdio.h>

int main()
{
	printf("IPPORT_RESERVED(port mac number) = %d\n", IPPORT_RESERVED);

	printf("IPPORT_USERRESERVED = %d\n", IPPORT_USERRESERVED);

	return 0;
}
