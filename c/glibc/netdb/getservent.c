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
 *	void setservent (int stayopen) [Function]
 *	This function opens the services database to begin scanning it.
 *	If the stayopen argument is nonzero, this sets a ﬂag so that subsequent calls to
 *	getservbyname or getservbyport will not close the database (as they usually would).
 *	This makes for more efciency if you call those functions several times, by avoiding
 *	reopening the database for each call.
 *	struct servent * getservent (void) [Function]
 *	This function returns the next entry in the services database. If there are no more
 *	entries, it returns a null pointer.
 *	void endservent (void) [Function]
 *	This function closes the services database.
 */
#include <stdio.h>
#include <netdb.h>

int main()
{
	struct servent *serv;

	setservent(1);

	while(serv = getservent())
	{
		printf("----\n");
		printf("name:		%s\n", serv->s_name);
		printf("aliases:	%s\n", serv->s_aliases[0]);
		printf("port:		%d\n", serv->s_port);
		printf("ntohs(prot):%d\n", ntohs(serv->s_port));
		printf("proto:		%s\n", serv->s_proto);
	}

	endservent();
}
