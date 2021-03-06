/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:17 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:43:21 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/**
 *	struct netent [Data Type]
 *	This data type is used to represent information about entries in the networks database.
 *	It has the following members:
 *	char *n_name
 *	This is the “ofcial” name of the network.
 *	char **n_aliases
 *	These are alternative names for the network, represented as a vector of
 *	strings. A null pointer terminates the array.
 *	int n_addrtype
 *	This is the type of the network number; this is always equal to AF_INET
 *	for Internet networks.
 *	unsigned long int n_net
 *	This is the network number. Network numbers are returned in host byte
 *	order; see Section 16.6.5 [Byte Order Conversion], page 408.
 *	Use the getnetbyname or getnetbyaddr functions to search the networks database for
 *	information about a specifc network. The information is returned in a statically-allocated
 *	structure; you must copy the information if you need to save it.
 *
 *
 *
 *	$ more /etc/networks 
 *	default 0.0.0.0
 *	loopback 127.0.0.0
 *	link-local 169.254.0.0
 */
#include <netdb.h>

struct netent{
	char *n_name;
	char **n_aliases;
	int n_addrtype;
	unsigned long int n_net;
};
