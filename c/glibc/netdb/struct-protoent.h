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
/*
 *	16.6.6 Protocols Database
 *	The communications protocol used with a socket controls low-level details of how data are
 *	exchanged. For example, the protocol implements things like checksums to detect errors
 *	in transmissions, and routing instructions for messages. Normal user programs have little
 *	reason to mess with these details directly.
 *	The default communications protocol for the Internet namespace depends on the com
 *	munication style. For stream communication, the default is TCP (“transmission control
 *	protocol”). For datagram communication, the default is UDP (“user datagram protocol”).
 *
 *	For reliable datagram communication, the default is RDP (“reliable datagram protocol”).
 *	You should nearly always use the default.
 *	Internet protocols are generally specifed by a name instead of a number. The network
 *	protocols that a host knows about are stored in a database. This is usually either derived
 *	from the fle ‘/etc/protocols’, or it may be an equivalent provided by a name server. You
 *	look up the protocol number associated with a named protocol in the database using the
 *	getprotobyname function.
 *	Here are detailed descriptions of the utilities for accessing the protocols database. These
 *	are declared in ‘netdb.h’.
 *	struct protoent [Data Type]
 *	This data type is used to represent entries in the network protocols database. It has
 *	the following members:
 *	char *p_name
 *	This is the ofcial name of the protocol.
 *	char **p_aliases
 *	These are alternate names for the protocol, specifed as an array of strings.
 *	The last element of the array is a null pointer.
 *	int p_proto
 *	This is the protocol number (in host byte order); use this member as the
 *	protocol argument to socket.
 *	You can use getprotobyname and getprotobynumber to search the protocols database
 *	for a specifc protocol. The information is returned in a statically-allocated structure; you
 *	must copy the information if you need to save it across calls.
 */
#include <netdb.h>

struct protoent{
	char *p_name;
	char **p_aliases;
	int p_proto;
};



