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

int sched_getaffinity (pid t pid, size t cpusetsize, cpu set t [Function]
*cpuset)
This functions stores the CPU afnity mask for the process or thread with the ID pid
in the cpusetsize bytes long bitmap pointed to by cpuset. If successful, the function
always initializes all bits in the cpu_set_t object and returns zero.
If pid does not correspond to a process or thread on the system the or the function
fails for some other reason, it returns -1 and errno is set to represent the error
condition.
ESRCH No process or thread with the given ID found.
EFAULT The pointer cpuset is does not point to a valid object.
This function is a GNU extension and is declared in ‘sched.h’.
Note that it is not portably possible to use this information to retrieve the information
for diﬀerent POSIX threads. A separate interface must be provided for that.

*/
#include <stdio.h>


#define __USE_GNU
#include <sched.h>

//int sched_getaffinity (pid t pid, size t cpusetsize, cpu set t *cpuset)

int main()
{
    cpu_set_t cpuset;

	CPU_ZERO(&cpuset);
    
    int ret = sched_getaffinity(getpid(), sizeof(cpu_set_t), &cpuset);
    
    printf("ret = %d, cpuset(%d)\n", ret, cpuset);
    
	return 0;
}
