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
 *	struct hostent * gethostbyaddr (const char *addr, size t length, [Function]
 *	int format)
 *	The gethostbyaddr function returns information about the host with Internet ad
 *	dress addr. The parameter addr is not really a pointer to char - it can be a pointer to
 *	an IPv4 or an IPv6 address. The length argument is the size (in bytes) of the address
 *	at addr. format specifes the address format; for an IPv4 Internet address, specify a
 *	value of AF_INET; for an IPv6 Internet address, use AF_INET6.
 *	If the lookup fails, gethostbyaddr returns a null pointer.
 *	If the name lookup by gethostbyname or gethostbyaddr fails, you can fnd out the
 *	reason by looking at the value of the variable h_errno. (It would be cleaner design for
 *	these functions to set errno, but use of h_errno is compatible with other systems.)
 *	Here are the error codes that you may fnd in h_errno:
 *	HOST_NOT_FOUND
 *	No such host is known in the database.
 *	TRY_AGAIN
 *	This condition happens when the name server could not be contacted. If you
 *	try again later, you may succeed then.
 *	NO_RECOVERY
 *	A non-recoverable error occurred.
 *	NO_ADDRESS
 *	The host database contains an entry for the name, but it doesn’t have an
 *	associated Internet address.
 *	The lookup functions above all have one in common: they are not reentrant and therefore
 *	unusable in multi-threaded applications. Therefore provides the GNU C library a new set
 *	of functions which can be used in this context.
 */
#include <netdb.h>

struct hostent * gethostbyaddr (const char *addr, size t length, int format);
