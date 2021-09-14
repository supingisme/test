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
/*	IPv6 Internet host addresses have 128 bits and are packaged inside a structure of type
 *	struct in6_addr.
 *	The following basic defnitions for Internet addresses are declared in the header fle
 *	‘netinet/in.h’:
 *	struct in_addr [Data Type]
 *	This data type is used in certain contexts to contain an IPv4 Internet host address.
 *	It has just one feld, named s_addr, which records the host address number as an
 *	uint32_t.
 *	uint32_t INADDR_LOOPBACK [Macro]
 *	You can use this constant to stand for “the address of this machine,” instead of fnding
 *	its actual address. It is the IPv4 Internet address ‘127.0.0.1’, which is usually called
 *	‘localhost’. This special constant saves you the trouble of looking up the address of
 *	your own machine. Also, the system usually implements INADDR_LOOPBACK specially,
 *	avoiding any network trafc for the case of one machine talking to itself.
 *
 */

#include <netinet/in.h>

struct in_addr{
	uint32_t s_addr;
};
