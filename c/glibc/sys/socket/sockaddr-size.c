/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:29 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netpacket/packet.h>   /* struct sockaddr_ll */
#include <sys/un.h>             /* unsocket head file */
#include <sys/types.h>
#include <unistd.h>             /* socket close will use */
#include <netinet/in.h>         /* htons/htonl*/

int main()
{
	struct sockaddr_in addr_in;
	struct sockaddr_ll addr_ll;
	struct sockaddr_un addr_un;

	printf("sizeof(struct sockaddr_in) = %d\n", sizeof(addr_in));
	printf("sizeof(struct sockaddr_ll) = %d\n", sizeof(addr_ll));
	printf("sizeof(struct sockaddr_un) = %d\n", sizeof(addr_un));
}
