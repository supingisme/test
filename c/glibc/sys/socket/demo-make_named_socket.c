/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:29 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>


int
make_named_socket (const char *filename)
{
	struct sockaddr_un name;
	int sock;
	size_t size;
	/* Create the socket. */
	sock = socket (PF_LOCAL, SOCK_DGRAM, 0);
	if (sock < 0)
	{
		perror ("socket");
		exit (EXIT_FAILURE);
	}
	/* Bind a name to the socket. */
	name.sun_family = AF_LOCAL;
	strncpy (name.sun_path, filename, sizeof (name.sun_path));
	name.sun_path[sizeof (name.sun_path) - 1] = ’\0’;
	/* The size of the address is
	 * the oﬀset of the start of the flename,
	 * plus its length,
	 * plus one for the terminating null byte.
	 * Alternatively you can just do:
	 * size = SUN LEN (&name);
	 * */
	size = (offsetof (struct sockaddr_un, sun_path)
			+ strlen (name.sun_path) + 1);
	if (bind (sock, (struct sockaddr *) &name, size) < 0)
	{
		perror ("bind");
		exit (EXIT_FAILURE);
	}
	return sock;
}
