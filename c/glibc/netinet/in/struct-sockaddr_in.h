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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:57:39 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:52:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/*
16.6.1 Internet Socket Address Formats
In the Internet namespace, for both IPv4 (AF_INET) and IPv6 (AF_INET6), a socket address
consists of a host address and a port on that host. In addition, the protocol you choose
serves eﬀectively as a part of the address because local port numbers are meaningful only
within a particular protocol.
The data types for representing socket addresses in the Internet namespace are defned
in the header fle ‘netinet/in.h’.

struct sockaddr_in [Data Type]
This is the data type used to represent socket addresses in the Internet namespace.
It has the following members:
sa_family_t sin_family
This identifes the address family or format of the socket address. You
should store the value AF_INET in this member. See Section 16.3 [Socket
Addresses], page 391.
struct in_addr sin_addr
This is the Internet address of the host machine. See Section 16.6.2 [Host
Addresses], page 398, and Section 16.6.2.4 [Host Names], page 402, for
how to get a value to store here.
unsigned short int sin_port
This is the port number. See Section 16.6.3 [Internet Ports], page 406.

*/
#include <netinet/in.h>

struct sockaddr_in{
    sa_family_t sin_family;
    struct in_addr sin_addr;
    unsigned short int sin_port;
    
};