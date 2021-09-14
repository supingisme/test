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
 *	int sethostid (long int id) [Function]
 *	The sethostid function sets the “host ID” of the host machine to id. Only privileged
 *	processes are permitted to do this. Usually it happens just once, at system boot time.
 *	The proper way to establish the primary IP address of a system is to confgure the IP
 *	address resolver to associate that IP address with the system’s host name as returned
 *	by gethostname. For example, put a record for the system in ‘/etc/hosts’.
 *	See gethostid above for more information on host ids.
 *	The return value is 0 on success and -1 on failure. The following errno error condi
 *	tions are defned for this function:
 *	EPERM This process cannot set the host name because it is not privileged.
 *	ENOSYS The operating system does not support setting the host ID. On some
 *	systems, the host ID is a meaningless but unique number hard-coded for
 *	each machine.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char name[256];

	int id = gethostid();

	int ret = sethostid(id);

	printf("%d. ret = %d\n", id, ret);

	return 0;
}
