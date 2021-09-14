/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 18:06:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:05 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */
#include <stdio.h>

// mul(a, b)
// int a, b;
// {
// __asm (
   // "mov ax, word ptr 8[bp]"
   // "imul ax word ptr 10[bp]"
// );
// }


int main()
{
// __asm__ (
	// "push	%rbp"
// );

    int a=10, b;
    
    // b = a 操作
    asm(
        "movl %1, %%eax;"
        "movl %%eax, %0;"
        :"r="(b)
        :"r"(a)
        :"%eax"
    );

    printf("%d, %d\n", a, b);
    
	return 0;
}
