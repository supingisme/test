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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 08:48:17 CST. */
#include <netinet/icmp6.h>

struct icmp6_filter {
	...
};

struct icmp6_filter myfilt;
fd = socket (AF_INET6, SOCK_RAW, IPPROTO_ICMPV6);
ICMP6_FILTER_SETBLOCKALL (&myfilt);
ICMP6_FILTER_SETPASS (ND_ROUTER_ADVERT, &myfilt);
Setsockopt (fd, IPPROTO_ICMPV6, ICMP6_FILTER. &myfilt, sizeof (myfilt));
