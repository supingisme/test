/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:43 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:17 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:11 CST. */
#include "unp.h"

struct addrinfo *host_serv (const char *hostname, const char *service, int family, ints socktype);

#include "unp.h"
struct addrinfo *
host_serv(const char *host, const char *serv, int family, int socktype)
{
	 int n;
	 struct addrinfo hints, *res;
	 bzero (&hints, sizeof (struct addrinfo));
	 hints.ai_flags = AI_CANONNAME; /* always return canonical name */
	 hints.ai_family = family; /* AF_UNSPEC, AF_INET, AF_INET6, etc. */
	 hints.ai_socktype = socktype; /* 0, SOCK_STREAM, SOCK_DGRAM, etc. */
	 if ( (n = getaddrinfo(host, serv, &hints, &res)) != 0)
		return (NULL);
	 return (res); /* return pointer to first on linked list */
}
