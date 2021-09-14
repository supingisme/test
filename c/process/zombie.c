/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 24日 星期一 08:17:28 CST. */


#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *	所谓僵尸进程：
 *
 *		父进程存在，子进程exit，会导致子进程成为僵尸进程。
 */

int main ()
{
	pid_t child_pid;
	/* Create a child process. */
	child_pid = fork ();
	if (child_pid > 0) {
		/* This is the parent process. Sleep for a minute. */
		sleep (60);
		//exit(0);
	}
	else {
		/* This is the child process. Exit immediately. */
		exit (0);
		//sleep(30);
	}
	return 0;
}
