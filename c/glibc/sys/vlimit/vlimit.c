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
/**
int vlimit (int resource, int limit) [Function]
vlimit sets the current limit for a resource for a process.
resource identifes the resource:
LIM_CPU Maximum CPU time. Same as RLIMIT_CPU for setrlimit.
LIM_FSIZE
Maximum fle size. Same as RLIMIT_FSIZE for setrlimit.
LIM_DATA Maximum data memory. Same as RLIMIT_DATA for setrlimit.
LIM_STACK
Maximum stack size. Same as RLIMIT_STACK for setrlimit.
LIM_CORE Maximum core fle size. Same as RLIMIT_COR for setrlimit.
LIM_MAXRSS
Maximum physical memory. Same as RLIMIT_RSS for setrlimit.
The return value is zero for success, and -1 with errno set accordingly for failure:
EPERM The process tried to set its current limit beyond its maximum limit.

*/

#include <sys/vlimit.h>
//#include <sys/resource.h>
#include <stdio.h>


//int vlimit (int resource, int limit);

// LIM_CPU Maximum CPU time. Same as RLIMIT_CPU for setrlimit.
// LIM_FSIZE Maximum fle size. Same as RLIMIT_FSIZE for setrlimit.
// LIM_DATA Maximum data memory. Same as RLIMIT_DATA for setrlimit.
// LIM_STACK Maximum stack size. Same as RLIMIT_STACK for setrlimit.
// LIM_CORE Maximum core fle size. Same as RLIMIT_COR for setrlimit.
// LIM_MAXRSS Maximum physical memory. Same as RLIMIT_RSS for setrlimit.

// The return value is zero for success, and -1 with errno set accordingly for failure:
// EPERM The process tried to set its current limit beyond its maximum limit.

int main()
{
    printf("%d\n", vlimit(LIM_CPU, 256));
    
    // struct rlimit rlimit;
    
    // getrlimit(LIM_CPU, &rlimit);

    // printf("rlim_cur = %d\n", rlimit.rlim_cur);
    // printf("rlim_max = %d\n", rlimit.rlim_max);
    
    return 0;
}