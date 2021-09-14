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
 *	16.6.4 The Services Database
 *	The database that keeps track of “well-known” services is usually either the fle
 *	‘/etc/services’ or an equivalent from a name server. You can use these utilities, declared
 *	in ‘netdb.h’, to access the services database.
 *
 *	struct servent [Data Type]
 *	This data type holds information about entries from the services database. It has the
 *	following members:
 *	char *s_name
 *	This is the “ofcial” name of the service.
 *	char **s_aliases
 *	These are alternate names for the service, represented as an array of
 *	strings. A null pointer terminates the array.
 *	int s_port
 *	This is the port number for the service. Port numbers are given in network
 *	byte order; see Section 16.6.5 [Byte Order Conversion], page 408.
 *	char *s_proto
 *	This is the name of the protocol to use with this service. See Section 16.6.6
 *	[Protocols Database], page 408.
 *	To get information about a particular service, use the getservbyname or getservbyport
 *	functions. The information is returned in a statically-allocated structure; you must copy
 *	the information if you need to save it across calls.
 */
#include <netdb.h>

struct servent{
	char *s_name;
	char **s_aliases;
	int s_port;
	char *s_proto;
};
