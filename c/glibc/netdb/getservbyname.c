/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:17 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:43:21 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/*
 *	struct servent * getservbyname (const char *name, const char [Function]
 *	*proto)
 *	The getservbyname function returns information about the service named name us
 *	ing protocol proto. If it can’t fnd such a service, it returns a null pointer.
 *	This function is useful for servers as well as for clients; servers use it to determine
 *	which port they should listen on (see Section 16.9.2 [Listening for Connections],
 *	page 414).
 */
#include <stdio.h>
#include <netdb.h>
/**
 *	struct servent *getservbyname(char *name, char *proto);
 *	name: 一个服务的名称
 *	proto: 某个服务器使用的协议
 *	如果没有查到这个服务，返回NULL
 *
 *	需要包含incude<netdb.h>
 */
int main()
{
	struct servent *ser;

	if(ser = getservbyname("ftp", "tcp"))
	{
		printf("name:		%s\n", ser->s_name);
		printf("port:		%d\n", ntohs(ser->s_port));
		printf("protocol:	%s\n", ser->s_proto);
		printf("alias:		%s\n", ser->s_aliases[0]);
	}	
	else
	{
		printf("there is no such a service\n");
	}
	printf("---\n");
	if(ser = getservbyname("http", "tcp"))
	{
		printf("name:		%s\n", ser->s_name);
		printf("port:		%d\n", ntohs(ser->s_port));
		printf("protocol:	%s\n", ser->s_proto);
		printf("alias:		%s\n", ser->s_aliases[0]);
	}	
	else
	{
		printf("there is no such a service\n");
	}
	printf("---\n");
	if(ser = getservbyname("adsfa", "tcp"))
	{
		printf("name:		%s\n", ser->s_name);
		printf("port:		%d\n", ntohs(ser->s_port));
		printf("protocol:	%s\n", ser->s_proto);
		printf("alias:		%s\n", ser->s_aliases[0]);
	}	
	else
	{
		printf("there is no such a service\n");
	}



}	
