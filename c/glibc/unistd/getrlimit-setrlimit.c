/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */


/**
 *	getrlimit, setrlimit - control maximum resource consumption
 *	
 *	The getrlimit and setrlimit system calls allow a process to read and set limits on the system
 *	resources that it can consume. You may be familiar with the ulimit shell command, which enables
 *	you to restrict the resource usage of programs you run; [4] these system calls allow a program to do
 *	this programmatically.
 */

#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
int main ()
{
	struct rlimit rl;
	/* Obtain the current limits. */
	getrlimit (RLIMIT_CPU, &rl);
	/* Set a CPU limit of 1 second. */
	rl.rlim_cur = 1;
	setrlimit (RLIMIT_CPU, &rl);
	/* Do busy work. */
	while (1);
	return 0;
}
