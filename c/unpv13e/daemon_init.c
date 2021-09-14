/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:43 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:17 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:11 CST. */
#include	"unp.h"
#include	<syslog.h>

#define	MAXFD	64

extern int	daemon_proc;	/* defined in error.c */

int
daemon_init(const char *pname, int facility)
{
	int		i;
	pid_t	pid;

	if ( (pid = Fork()) < 0)
		return (-1);
	else if (pid)
		_exit(0);			/* parent terminates */

	/* child 1 continues... */

	if (setsid() < 0)			/* become session leader */
		return (-1);

	Signal(SIGHUP, SIG_IGN);
	if ( (pid = Fork()) < 0)
		return (-1);
	else if (pid)
		_exit(0);			/* child 1 terminates */

	/* child 2 continues... */

	daemon_proc = 1;			/* for err_XXX() functions */

	chdir("/");				/* change working directory */

	/* close off file descriptors */
	for (i = 0; i < MAXFD; i++)
		close(i);

	/* redirect stdin, stdout, and stderr to /dev/null */
	open("/dev/null", O_RDONLY);
	open("/dev/null", O_RDWR);
	open("/dev/null", O_RDWR);

	openlog(pname, LOG_PID, facility);

	return (0);				/* success */
}

/* Usage
3 int
4 main(int argc, char **argv)
5 {
6 int listenfd, connfd;
7 socklen_t addrlen, len;
8 struct sockaddr *cliaddr;
9 char buff[MAXLINE];
10 time_t ticks;
11 if (argc < 2 || argc > 3)
12 err_quit("usage: daytimetcpsrv2 [ <host> ] <service or port>");
13 daemon_init(argv[0], 0);
14 if (argc == 2)
*/

