/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:43 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:40 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:24 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */

#ifndef __SYSDEP_X86_64_BARRIER_H
#define __SYSDEP_X86_64_BARRIER_H

/* Copied from include/asm-x86_64 for use by userspace. */
#define mb() 	asm volatile("mfence":::"memory")

#endif

#include <stdio.h>

// $ gcc volatile.c 
// volatile.c:13:2: 错误：#error only <linux/bitops.h> can be included directly
// #error only <linux/bitops.h> can be included directly
#ifndef _LINUX_BITOPS_H
#error only <linux/bitops.h> can be included directly
#endif

int main()
{
    mb();
    
    //volatile 关键字，
    //每次从内存重新装载内容，
    //而不是从寄存器拷贝内容
    volatile int a;
    
    return 0;
}
