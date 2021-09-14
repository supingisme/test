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
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <malloc.h>
#include <string.h>


#define PORT 5555
#define MESSAGE "Yow!!! Are we having fun yet?!?"
#define SERVERHOST "localhost"

void
init_sockaddr (struct sockaddr_in *name,
		const char *hostname,
		uint16_t port)
{
	struct hostent *hostinfo;
    
	name->sin_family = AF_INET;
	name->sin_port = htons (port);
	name->sin_addr.s_addr = inet_addr("127.0.0.1");
    
	hostinfo = gethostbyname (hostname);
	if (hostinfo == NULL)
	{
		fprintf (stderr, "Unknown host %s.\n", hostname);
		exit (EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout, "Host %s.\n", hostinfo->h_name);
	}
	name->sin_addr = *(struct in_addr *) hostinfo->h_addr;
}

void
write_to_server (int filedes)
{
	int nbytes;
	nbytes = write (filedes, MESSAGE, strlen (MESSAGE) + 1);
	if (nbytes < 0)
	{
		perror ("write");
		exit (EXIT_FAILURE);
	}
}
int
main (void)
{
	int sock;
	struct sockaddr_in servername;
	/* Create the socket. */
	sock = socket (PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror ("socket (client)");
		exit (EXIT_FAILURE);
	}
	/* Connect to the server. */
	init_sockaddr (&servername, SERVERHOST, PORT);
	if (0 > connect (sock,
				(struct sockaddr *) &servername,
				sizeof (servername)))
	{
		perror ("connect (client)");
		exit (EXIT_FAILURE);
	}
	/* Send data to the server. */
	write_to_server (sock);
	close (sock);
	exit (EXIT_SUCCESS);
}
