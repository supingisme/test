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
//The gethostbyname and gethostbyaddr functions only support IPv4. The API for resolving IPv6 addresses went through several iterations, as will be described in Section 11.20(See 8.9.20); the final result is the getaddrinfo function. The getaddrinfo function handles both name-to-address and service-to-port translation, and returns sockaddr structures instead of a list of addresses. These sockaddr structures can then be used by the socket functions directly. In this way, the getaddrinfo function hides all the protocol dependencies in the library function, which is where they belong. The application deals only with the socket address structures that are filled in by getaddrinfo. This function is defined in the POSIX specification.
//

#include <netdb.h>
int getaddrinfo (const char *hostname, const char *service, 
		const struct addrinfo *hints, struct addrinfo **result) ;

//example
//struct addrinfo hints, *res;
//bzero(&hints, sizeof(hints) ) ;
//hints.ai_flags = AI_CANONNAME;
//hints.ai_family = AF_INET;
//getaddrinfo("freebsd4", "domain", &hints, &res);
