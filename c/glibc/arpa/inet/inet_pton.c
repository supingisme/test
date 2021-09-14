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
 *	将十进制IP字符串  转化为   长整形
 *
 */

/*	int inet_pton (int af, const char *cp, void *buf) [Function]
 *	This function converts an Internet address (either IPv4 or IPv6) from presentation
 *	(textual) to network (binary) format. af should be either AF_INET or AF_INET6, as
 *	appropriate for the type of address being converted. cp is a pointer to the input
 *	string, and buf is a pointer to a buﬀer for the result. It is the caller’s responsibility
 *	to make sure the buﬀer is large enough.
 */
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int inet_pton(int family, const char *strptr, void *addrptr);
	//返回
	//成功：1
	//输入格式不对：0
	//错误：-1

/**
 * 仅支持IPv4的inet_pton简化版本
 *
 */
int 
inet_pton(int family, const char *strptr, void *addrptr)
{
	if(family == AF_INET)
	{
		struct in_addr in_val;
		
		if(inet_aton(strptr, &in_val))
		{
			memcpy(addrptr, &in_val, sizeof(struct in_addr));
			return 1;
		}
		return 0;
	}
	errno = EAFNOSUPPORT;
	return -1;
}

int main()
{
	
}

