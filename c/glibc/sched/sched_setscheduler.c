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

int sched_setscheduler (pid t pid, int policy, const struct [Function]
sched param *param)
This function sets both the absolute priority and the scheduling policy for a process.

It assigns the absolute priority value given by param and the scheduling policy policy
to the process with Process ID pid, or the calling process if pid is zero. If policy is
negative, sched_setscheduler keeps the existing scheduling policy.
The following macros represent the valid values for policy:
SCHED_OTHER
Traditional Scheduling
SCHED_FIFO
First In First Out
SCHED_RR Round Robin
On success, the return value is 0. Otherwise, it is -1 and ERRNO is set accordingly.
The errno values specifc to this function are:
EPERM
• The calling process does not have CAP_SYS_NICE permission and pol
icy is not SCHED_OTHER (or it’s negative and the existing policy is not
SCHED_OTHER.
• The calling process does not have CAP_SYS_NICE permission and its
owner is not the target process’ owner. I.e., the eﬀective uid of the
calling process is neither the eﬀective nor the real uid of process pid.
ESRCH There is no process with pid pid and pid is not zero.
EINVAL
• policy does not identify an existing scheduling policy.
• The absolute priority value identifed by *param is outside the valid
range for the scheduling policy policy (or the existing scheduling
policy if policy is negative) or param is null. sched_get_priority_
max and sched_get_priority_min tell you what the valid range is.
• pid is negative.



int sched_setscheduler (pid t pid, int policy, const struct sched param *param)

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
