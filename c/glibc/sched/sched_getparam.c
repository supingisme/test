/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:21 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/*

int sched_getparam (pid t pid, const struct sched param *param) [Function]
This function returns a process’ absolute priority.
pid is the Process ID (pid) of the process whose absolute priority you want to know.
param is a pointer to a structure in which the function stores the absolute priority of
the process.
On success, the return value is 0. Otherwise, it is -1 and ERRNO is set accordingly.
The errno values specifc to this function are:
ESRCH There is no process with pid pid and it is not zero.
EINVAL pid is negative.


获取和设置调度参数

*/
#include <sched.h>
#include <stdio.h>

// struct sched_param{
    // int sched_priority;
// };
//int sched_getparam (pid t pid, const struct sched param *param)

int main()
{
    struct sched_param sp;
    
    printf("%d:%d\n", getpid(), sched_setparam (getpid(), &sp));
    
    printf("%d\n", sp.sched_priority);
    
	return 0;
}
