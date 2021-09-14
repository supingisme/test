/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*
 *	pid_t waitpid (pid t pid, int *status-ptr, int options) [Function]
 *	The waitpid function is used to request status information from a child process whose
 *	process ID is pid. Normally, the calling process is suspended until the child process
 *	makes status information available by terminating.
 *	Other values for the pid argument have special interpretations. A value of -1 or
 *	WAIT_ANY requests status information for any child process; a value of 0 or WAIT_
 *	MYPGRP requests information for any child process in the same process group as the
 *	calling process; and any other negative value − pgid requests information for any
 *	child process whose process group ID is pgid.
 *	If status information for a child process is available immediately, this function re
 *	turns immediately without waiting. If more than one eligible child process has status
 *	information available, one of them is chosen randomly, and its status is returned im
 *	mediately. To get the status from the other eligible child processes, you need to call
 *	waitpid again.
 *	The options argument is a bit mask. Its value should be the bitwise OR (that is, the
 *	‘|’ operator) of zero or more of the WNOHANG and WUNTRACED ﬂags. You can use the
 *	WNOHANG ﬂag to indicate that the parent process shouldn’t wait; and the WUNTRACED
 *	ﬂag to request status information from stopped processes as well as processes that
 *	have terminated.
 */

#include <sys/wait.h>
//pid_t waitpid (pid t pid, int *status-ptr, int options);

//杀死僵尸进程
/*
# 销毁僵尸进程2：使用waitpid函数
```
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int* status, int option);
//成功时返回子进程ID或0,失败时返回-1
```
- pid: 目标子进程id，若传递-1,则与wait函数相同，可以等待任意子进程终止 <br>
- option: 传递常量WNOHANG，即使没有终止的子进程也不会进入阻塞状态，而是返回0并退出
*/

#include <signal.h>
/**
 *	Here’s an example of how to use waitpid to get the status from all child processes
 *	that have terminated, without ever waiting. This function is designed to be a handler for
 *	SIGCHLD, the signal that indicates that at least one child process has terminated.
 */
void
sigchld_handler (int signum)
{
	int pid, status, serrno;
	serrno = errno;
	while (1)
	{
		pid = waitpid (WAIT_ANY, &status, WNOHANG);
		if (pid < 0)
		{
			perror ("waitpid");
			break;
		}
		if (pid == 0)
			break;
		notice_termination (pid, status);
	}
	errno = serrno;
}

int main()
{
	

	return 0;
}
