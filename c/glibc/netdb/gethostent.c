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
 *	You can also scan the entire hosts database one entry at a time using sethostent,
 *	gethostent and endhostent. Be careful when using these functions because they are not
 *	reentrant.
 *	void sethostent (int stayopen) [Function]
 *	This function opens the hosts database to begin scanning it. You can then call
 *	gethostent to read the entries.
 *	If the stayopen argument is nonzero, this sets a ﬂag so that subsequent calls to
 *	gethostbyname or gethostbyaddr will not close the database (as they usually would).
 *	This makes for more efciency if you call those functions several times, by avoiding
 *	reopening the database for each call.
 *
 *	struct hostent * gethostent (void) [Function]
 *	This function returns the next entry in the hosts database. It returns a null pointer
 *	if there are no more entries.
 *	void endhostent (void) [Function]
 *	This function closes the hosts database.
 */
#include <netdb.h>

#include <stdio.h>

void sethostent (int stayopen);
struct hostent * gethostent (void);
void endhostent (void);

int main()
{
	//sethostent(1);

	struct hostent *host = gethostent();

	printf("%s\n", host->h_name);

	//endhostent();

	return 0;
}
