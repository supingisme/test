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
//########
//Figure 27.12 shows the format of the ancillary data object used to send and receive the routing header. Six functions are defined to create and process the routing header. The following three functions build an option to send:

#include <netinet/in.h>
socklen_t inet6_rth_space(int type, int segments) ;
//Returns: positive number of bytes if OK, 0 on error
void *inet6_rth_init(void *rthbuf, socklen_t rthlen, int type, int segments);
//Returns: non-null pointer if OK, NULL on error
int inet6_rth_add(void *rthbuf, const struct in6_addr *addr);
//Returns: 0 if OK, -1 on error

//inet6_rth_space returns the number of bytes required to hold a routing header of the specified type (normally specified as IPV6_RTHDR_TYPE_0) with the specified number of segments.
//inet6_rth_init initializes the buffer pointed to by rthbuf to contain a routing header of the specified type and the specified number of segments. The return value is the pointer to the buffer, and this pointer is then used as an argument to the next function.
//inet6_rth_init returns NULL if an error occurs, for instance, when the supplied buffer is not large enough.
//inet6_rth_add adds the IPv6 address pointed to by addr to the end of the routing header being constructed. When successful, the segleft member of the routing header is updated to account for the new address.


