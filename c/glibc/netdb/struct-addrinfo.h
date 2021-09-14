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
#include <netdb.h>

struct addrinfo {
	int ai_flags; /* AI_PASSIVE, AI_CANONNAME */
	int ai_family; /* AF_xxx */
	int ai_socktype; /* SOCK_xxx */
	int ai_protocol; /* 0 or IPPROTO_xxx for IPv4 and IPv6 */
	socklen_t ai_addrlen; /* length of ai_addr */
	char *ai_canonname; /* ptr to canonical name for host */
	struct sockaddr *ai_addr; /* ptr to socket address structure */
	struct addrinfo *ai_next; /* ptr to next structure in linked list */
};


/** example
struct addrinfo hints, *res;
bzero(&hints, sizeof(hints) ) ;
hints.ai_flags = AI_CANONNAME;
hints.ai_family = AF_INET;
getaddrinfo("freebsd4", "domain", &hints, &res);
*/
