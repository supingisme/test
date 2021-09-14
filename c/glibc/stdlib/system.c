/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
 *	int system (const char *command) [Function]
 *	This function executes command as a shell command. In the GNU C library, it
 *	always uses the default shell sh to run the command. In particular, it searches the
 *	directories in PATH to fnd programs to execute. The return value is -1 if it wasn’t
 *	possible to create the shell process, and otherwise is the status of the shell process.
 *	See Section 26.6 [Process Completion], page 693, for details on how this status code
 *	can be interpreted.
 *	If the command argument is a null pointer, a return value of zero indicates that no
 *	command processor is available.
 *	This function is a cancellation point in multi-threaded programs. This is a problem
 *	if the thread allocates some resources (like memory, fle descriptors, semaphores or
 *	whatever) at the time system is called. If the thread gets canceled these resources stay
 *	allocated until the program ends. To avoid this calls to system should be protected
 *	using cancellation handlers.
 *	The system function is declared in the header fle ‘stdlib.h’.
 */

#include <stdlib.h>
//int system (const char *command);

#include <stdio.h>
#include <stdarg.h>

int sh_cmd(const char *fmt, ...)
{
	va_list arg;
	va_start(arg, fmt);

	char cmd[1024];
	vsprintf(cmd, fmt, arg);

	printf("%s\n", cmd);
	system(cmd);

	va_end(arg);
}


int main()
{	
	sh_cmd("echo RongTao: %s\n", "adsfdd");

	sh_cmd("./while1 ");

	printf("PID %d, PPID %d (main).\n", getpid(), getppid());

	while(1) {
		sleep(1);
	}

	return 0;
}
