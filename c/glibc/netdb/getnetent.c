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
 *	void setnetent (int stayopen) [Function]
 *	This function opens and rewinds the networks database.
 *	If the stayopen argument is nonzero, this sets a ﬂag so that subsequent calls to
 *	getnetbyname or getnetbyaddr will not close the database (as they usually would).
 *	This makes for more efciency if you call those functions several times, by avoiding
 *	reopening the database for each call.
 *	struct netent * getnetent (void) [Function]
 *	This function returns the next entry in the networks database. It returns a null
 *	pointer if there are no more entries.
 *	void endnetent (void) [Function]
 *	This function closes the networks database.
 *
 *	$ ./a.out 
 *	netent: n_name: default
 *	netent: n_aliases[0]: (null)
 *	netent: n_addrtype: 2
 *	netent: n_net: 0
 *	netent: n_name: loopback
 *	netent: n_aliases[0]: (null)
 *	netent: n_addrtype: 2
 *	netent: n_net: 2130706432
 *	netent: n_name: link-local
 *	netent: n_aliases[0]: (null)
 *	netent: n_addrtype: 2
 *	netent: n_net: -1442971648
 *
 *
 */
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

int main()
{
	struct netent *net;

	setnetent(1);

	while(net = getnetent())
	{
		printf("netent: n_name: %s\n", net->n_name);
		printf("netent: n_aliases[0]: %s\n", net->n_aliases[0]);
		printf("netent: n_addrtype: %d\n", net->n_addrtype);
		printf("netent: n_net: %d\n", net->n_net);
	}

	endnetent();

	return 0;
}
