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
/*	char * inet_ntoa (struct in addr addr) [Function]
 *	This function converts the IPv4 Internet host address addr to a string in the standard
 *	numbers-and-dots notation. The return value is a pointer into a statically-allocated
 *	buﬀer. Subsequent calls will overwrite the same buﬀer, so you should copy the string
 *	if you need to save it.
 *	In multi-threaded programs each thread has an own statically-allocated buﬀer. But
 *	still subsequent calls of inet_ntoa in the same thread will overwrite the result of the
 *	last call.
 *	Instead of inet_ntoa the newer function inet_ntop which is described below should
 *	be used since it handles both IPv4 and IPv6 addresses.
 *
 */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 *	将一个长整形转化为一个十进制IP
 *	char *inet_ntoa(struct in_addr in);
 *	其中in为in_addr类型的结构体
 *	struct in_addr
 *	{
 *		uint32_t s_addr;
 *	}
 */

int main()
{
	struct in_addr in;
	long int ld = 16777343;
	in.s_addr = ld;
	printf("inet_ntoa: %s\n", inet_ntoa(in));

	return 1;
}

