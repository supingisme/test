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
 *	pid_t setsid (void) [Function]
 *	The setsid function creates a new session. The calling process becomes the session
 *	leader, and is put in a new process group whose process group ID is the same as the
 *	process ID of that process. There are initially no other processes in the new process
 *	group, and no other process groups in the new session.
 *	This function also makes the calling process have no controlling terminal.
 *	The setsid function returns the new process group ID of the calling process if suc
 *	cessful. A return value of -1 indicates an error. The following errno error conditions
 *	are defned for this function:
 *	EPERM The calling process is already a process group leader, or there is already
 *	another process group around that has the same process group ID.
 *
 */
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <syslog.h>
#include <stdlib.h>

#define MAXFD 64

int demo1()
{
	printf("setsid = %d\n", setsid());
	
	perror("setsid");

	return 0;
}

int demo2_daemon_init()
{
	int i;
	pid_t pid;
	
	if((pid=fork()) != 0)
	{
		printf("parent terminates.\n");
		exit(0);
	}
	setsid();
	perror("setsid: ");
	signal(SIGHUP, SIG_IGN);

	if((pid=fork()) != 0)
	{
		printf("1st child terminates.\n");
		exit(0);
	}
	chdir("/home/rongtao");
	perror("chdir: ");
	umask(0);
	for(i=0; i<MAXFD; i++)
	{
		printf("close fd = %d\n", i);
		close(i);
		perror("close: ");
	}	
	openlog("openlog_name", LOG_PID, 0);
	perror("openlog: ");

	return 0;
}

int main()
{
	//demo1();
	demo2_daemon_init();
	return 0;
}



