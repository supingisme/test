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
/**
 *	inet_aton
 *
 *	int inet_aton (const char *name, struct in addr *addr) [Function]
 *	This function converts the IPv4 Internet host address name from the standard
 *	numbers-and-dots notation into binary data and stores it in the struct in_addr
 *	that addr points to. inet_aton returns nonzero if the address is valid, zero if not.
 */

#include <arpa/inet.h>

/**
 *	将点分十进制字符串   转化为  32-bit网络字节二进制IPv4
 *
 *	"127.0.0.1" to 1001010001001
 */
int inet_aton(const char *strptr, struct in_addr *addrptr);

#include <stdio.h>

int main()
{
	struct in_addr addr;
	printf("%d\n", inet_aton("127.0.0.1", &addr));
	printf("%d\n", addr.s_addr);
	return 0;
}
