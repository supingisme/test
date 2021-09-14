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
//######
//The following three functions deal with a received routing header:
//
#include <netinet/in.h>
int inet6_rth_reverse(const void *in, void *out);
//Returns: 0 if OK, -1 on error
int inet6_rth_segments(const void *rthbuf);
//Returns: number of segments in routing header if OK, -1 on error
struct in6_addr *inet6_rth_getaddr(const void *rthbuf, int index);
//Returns: non-null pointer if OK, NULL on error
//
//
//inet6_rth_reverse takes a routing header that was received (pointed to by in) and creates a new routing header (in the buffer pointed to by out) that sends datagrams along the reverse of that path. The reversal can occur in place; that is, the in and out pointers can point to the same buffer.
//inet6_rth_segments returns the number of segments in the routing header described by rthbuf. When successful, the return value is greater than zero.
//inet6_rth_getaddr returns a pointer to the IPv6 address specified by index in the routing header described by rthbuf. index must have a value between zero and one less than the value returned by inet6_rth_segments, inclusive.
//To demonstrate these options, we create a UDP client and server. The client, shown in Figure 27.13, accepts a source route on the command line like the IPv4 TCP client we showed in Figure 27.6(See 9.16.3); the server prints the received source route and reverses it to send back to the client.
//
