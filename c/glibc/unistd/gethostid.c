/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*
 *	long int gethostid (void) [Function]
 *	This function returns the “host ID” of the machine the program is running on. By
 *	convention, this is usually the primary Internet IP address of that machine, converted
 *	to a long int. However, on some systems it is a meaningless but unique number which
 *	is hard-coded for each machine.
 *	This is not widely used. It arose in BSD 4.2, but was dropped in BSD 4.4. It is not
 *	required by POSIX.
 *	The proper way to query the IP address is to use gethostbyname on the results
 *	of gethostname. For more information on IP addresses, See Section 16.6.2 [Host
 *	Addresses], page 398.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char name[256];

	int id = gethostid();

	printf("%d\n", id);

	return 0;
}
