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

int sched_getscheduler (pid t pid) [Function]
This function returns the scheduling policy assigned to the process with Process ID
(pid) pid, or the calling process if pid is zero.
The return value is the scheduling policy. See sched_setscheduler for the possible
values.
If the function fails, the return value is instead -1 and errno is set accordingly.
The errno values specifc to this function are:
ESRCH There is no process with pid pid and it is not zero.
EINVAL pid is negative.
Note that this function is not an exact mate to sched_setscheduler because while
that function sets the scheduling policy and the absolute priority, this function gets
only the scheduling policy. To get the absolute priority, use sched_getparam.






int sched_setscheduler (pid t pid, int policy, const struct sched param *param);
int sched_getscheduler (pid t pid);

*/
#include <sched.h>
#include <stdio.h>

// struct sched_param{
    // int sched_priority;
// };


int main()
{
    struct sched_param sp;
    
    sp.sched_priority = 1;
    
    sched_setscheduler (getpid(), SCHED_FIFO, &sp);
    
    printf("%d:%d\n", getpid(), sched_getscheduler (getpid()));
    
    
	return 0;
}
