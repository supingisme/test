/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*
To create a socket in the local namespace, use the constant PF_LOCAL as the namespace
argument to socket or socketpair. This constant is defned in ‘sys/socket.h’.
int PF_LOCAL [Macro]
This designates the local namespace, in which socket addresses are local names, and
its associated family of protocols. PF_Local is the macro used by Posix.1g.
int PF_UNIX [Macro]
This is a synonym for PF_LOCAL, for compatibility’s sake.
int PF_FILE [Macro]
This is a synonym for PF_LOCAL, for compatibility’s sake.
The structure for specifying socket names in the local namespace is defned in the header
fle ‘sys/un.h’:
struct sockaddr_un [Data Type]
This structure is used to specify local namespace socket addresses. It has the following
members:
short int sun_family
This identifes the address family or format of the socket address. You
should store the value AF_LOCAL to designate the local namespace. See
Section 16.3 [Socket Addresses], page 391.
char sun_path[108]
This is the fle name to use.
Incomplete: Why is 108 a magic number? RMS suggests making this
a zero-length array and tweaking the following example to use alloca
to allocate an appropriate amount of storage based on the length of the
flename.
int SUN_LEN (struct sockaddr un * ptr)
The macro computes the length of socket address in the local namespace.
*/
#include <sys/un.h>

struct sockaddr_un {
    short int sun_family;
    char sun_path[108];
};
//or
struct sockaddr_un {
	sa_family_t sun_family; /* AF_LOCAL */
	char sun_path[104]; /* null-terminated pathname */
};
int SUN_LEN (struct sockaddr_un * ptr);


