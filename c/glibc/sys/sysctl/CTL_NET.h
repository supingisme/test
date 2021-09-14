/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */

/*
 *	CTL_NET: AF_INET, AF_LINK, AF_ROUTE, AF_UNSPEC
 *
 *	• AF_INET—Get or set variables affecting the Internet protocols. 
 *				The next level specifies the protocol using one of the 
 *				IPPROTO_xxx constants. FreeBSD 5.0 provides about 75 
 *				variables at this level, controlling features such as 
 *				whether the kernel should generate an ICMP redirect, 
 *				whether TCP should use the RFC 1323 options, whether UDP 
 *				checksums should be sent, and so on. We will show an 
 *				example of this use of sysctl at the end of this section.
 *	• AF_LINK—Get or set link-layer information such as the number of PPP interfaces.
 *	• AF_ROUTE—Return information on either the routing table or interface 
 *				list. We will describe this information shortly.
 *	• AF_UNSPEC—Get or set some socket-layer variables such as the maximum 
 *				size of a socket send or receive buffer.
 */

/**
 *	When the second element of the name array is AF_ROUTE, the third element 
 *	(a protocol number) is always 0 (since there are no protocols within the 
 *	AF_ROUTE family, as there are within the AF_INET family, for example), 
 *	the fourth element is an address family, and the fifth and sixth levels 
 *	specify what to do. We will summarize this in Figure 18.12.
 */
