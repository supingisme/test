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

int sched_setaffinity (pid t pid, size t cpusetsize, const cpu set t [Function]
*cpuset)

可以将某个进程绑定到一个特定的CPU。

This function installs the cpusetsize bytes long afnity mask pointed to by cpuset for
the process or thread with the ID pid. If successful the function returns zero and the
scheduler will in future take the afnity information into account.
If the function fails it will return -1 and errno is set to the error code:
ESRCH No process or thread with the given ID found.
EFAULT The pointer cpuset is does not point to a valid object.
EINVAL The bitset is not valid. This might mean that the afnity set might not
leave a processor for the process or thread to run on.
This function is a GNU extension and is declared in ‘sched.h’.




*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>


#define __USE_GNU
#include <sched.h>
#include <ctype.h>
#include <string.h>

//int sched_setaffinity (pid t pid, size t cpusetsize, const cpu set t *cpuset)

int main()
{
    long int ncpu = sysconf (_SC_NPROCESSORS_ONLN);
    
    cpu_set_t cpuset;

	CPU_ZERO(&cpuset);
    
    CPU_SET(ncpu>1?ncpu:1, &cpuset);
    
    int ret = sched_setaffinity(getpid(), sizeof(cpuset), &cpuset);
    
    printf("ret = %d\n", ret);
    
    int j;
    for(j=0;j<CPU_SETSIZE; j++)
    {
        if(CPU_ISSET(j, &cpuset))
        {
            printf("CPU_SETSIZE = %d, j = %d, cpuset = %d\n", CPU_SETSIZE, j, cpuset);
            CPU_CLR(j, &cpuset);
            printf("CPU_SETSIZE = %d, j = %d, cpuset = %d\n", CPU_SETSIZE, j, cpuset);
        }
    }
    
    
    
    ret = sched_getaffinity(getpid(), sizeof(cpuset), &cpuset);

    for(j=0;j<CPU_SETSIZE; j++)
    {
        if(CPU_ISSET(j, &cpuset))
        {
            printf("CPU_SETSIZE = %d, j = %d, cpuset = %d\n", CPU_SETSIZE, j, cpuset);
        }
    }
    
	return 0;
}
