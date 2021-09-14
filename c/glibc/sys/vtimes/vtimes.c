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
 *	vtimes and its vtimes data structure are declared in ‘sys/vtimes.h’.
 *	int vtimes (struct vtimes current, struct vtimes child) [Function]
 *	vtimes reports resource usage totals for a process.
 *	If current is non-null, vtimes stores resource usage totals for the invoking process
 *	alone in the structure to which it points. If child is non-null, vtimes stores resource
 *	usage totals for all past children (which have terminated) of the invoking process in
 *	the structure to which it points.
 */
#include <sys/vtimes.h>
#include <stdio.h>

// vtimes reports resource usage totals for a process.
//int vtimes (struct vtimes current, struct vtimes child);

int show(struct vtimes v)
{	
    printf("vm_utime = %d\n", v.vm_utime);
    printf("vm_stime = %d\n", v.vm_stime);
    printf("vm_idsrss = %d\n", v.vm_idsrss);
    printf("vm_ixrss = %d\n", v.vm_ixrss);
    printf("vm_maxrss = %d\n", v.vm_maxrss);
    printf("vm_majflt = %d\n", v.vm_majflt);
    printf("vm_minflt = %d\n", v.vm_minflt);
    printf("vm_nswap = %d\n", v.vm_nswap);
    printf("vm_inblk = %d\n", v.vm_inblk);
    printf("vm_oublk = %d\n", v.vm_oublk);
}


int main()
{
    struct vtimes current, child;
    
    vtimes(&current, &child);

    show(current);
    show(child);

	return 0;
}
