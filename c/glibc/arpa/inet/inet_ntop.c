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
/*	const char * inet_ntop (int af, const void *cp, char *buf, size t [Function]
 *	len)
 *	This function converts an Internet address (either IPv4 or IPv6) from network (bi
 *	nary) to presentation (textual) form. af should be either AF_INET or AF_INET6, as
 *	appropriate. cp is a pointer to the address to be converted. buf should be a pointer
 *	to a buﬀer to hold the result, and len is the length of this buﬀer. The return value
 *	from the function will be this buﬀer address.
 *
 */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
/**
 *
 *	将一个长整形转化为一个十进制IP字符串
 *
 *	const char *inet_ntop(	int family, 
 *							const void *addrptr,
 *							char *strptr,
 *							size_t len
 *						);
 *
 *	
 *
 */

#include <arpa/inet.h>

//const char *inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
	//返回
	//成功：返回指向结果的指针
	//错误：NULL

/**
 *	仅支持IPv4的inet_ntop简化版本
 */
const char *
inet_ntop_self(int family, const void *addrptr, char *strptr, size_t len)
{
	const u_char *p = (const u_char *)addrptr;

	if(family == AF_INET)
	{
		char temp[INET_ADDRSTRLEN];

		snprintf(temp, sizeof(temp), "%d.%d.%d.%d", p[0],p[1],p[2],p[3]);
	
		if(strlen(temp) >= len)
		{
			errno = ENOSPC;
			return NULL;
		}	
		strcpy(strptr, temp);
		return strptr;
	}
	errno = EAFNOSUPPORT;
	return NULL;

}

int main()
{
	return 0;
}
