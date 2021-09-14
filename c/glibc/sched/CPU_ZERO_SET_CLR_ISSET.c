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
 *	void CPU_ZERO (cpu set t *set) [Macro]
 *	This macro initializes the CPU set set to be the empty set.
 *	This macro is a GNU extension and is defned in ‘sched.h’.
 *	void CPU_SET (int cpu, cpu set t *set) [Macro]
 *	This macro adds cpu to the CPU set set.
 *	The cpu parameter must not have side eﬀects since it is evaluated more than once.
 *	This macro is a GNU extension and is defned in ‘sched.h’.
 *	void CPU_CLR (int cpu, cpu set t *set) [Macro]
 *	This macro removes cpu from the CPU set set.
 *	The cpu parameter must not have side eﬀects since it is evaluated more than once.
 *	This macro is a GNU extension and is defned in ‘sched.h’.
 *	int CPU_ISSET (int cpu, const cpu set t *set) [Macro]
 *	This macro returns a nonzero value (true) if cpu is a member of the CPU set set, and
 *	zero (false) otherwise.
 *	The cpu parameter must not have side eﬀects since it is evaluated more than once.
 *	This macro is a GNU extension and is defned in ‘sched.h’.
 */

#include <stdio.h>


#define __USE_GNU
#include <sched.h>



int main()
{
	cpu_set_t cpuset;

	CPU_ZERO(&cpuset);

	//CPU_SET(1, &cpuset);
	CPU_SET(8, &cpuset);

	printf("0x%x\n", cpuset);

    CPU_CLR(8, &cpuset);
    
	printf("0x%x\n", cpuset);
    
    if(CPU_ISSET(1, &cpuset))
        printf("0x%x\n", cpuset);
    
	return 0;
}
