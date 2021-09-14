/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:09 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*	uint32_t inet_addr (const char *name) [Function]
 *	This function converts the IPv4 Internet host address name from the standard
 *	numbers-and-dots notation into binary data. If the input is not valid, inet_addr
 *	returns INADDR_NONE. This is an obsolete interface to inet_aton, described
 *	immediately above. It is obsolete because INADDR_NONE is a valid address
 *	(255.255.255.255), and inet_aton provides a cleaner way to indicate error return.
 *
 */


#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 *	讲ip地址转化为一个长整形
 *	long inet_addr(char *cp);
 */

int main()
{
	char cp[] = "127.0.0.1";
	printf("inet_addr: %ld\n", inet_addr(cp));

	return 1;
}

