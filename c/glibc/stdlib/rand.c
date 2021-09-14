/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
19.8.1 ISO C Random Number Functions
This section describes the random number functions that are part of the ISO C standard.
To use these facilities, you should include the header fle ‘stdlib.h’ in your program.
int RAND_MAX [Macro]
The value of this macro is an integer constant representing the largest value the rand
function can return. In the GNU library, it is 2147483647, which is the largest signed
integer representable in 32 bits. In other libraries, it may be as low as 32767.
int rand (void) [Function]
The rand function returns the next pseudo-random number in the series. The value
ranges from 0 to RAND_MAX.
*/

#include <stdio.h>
#include <stdlib.h>



int main()
{
    RAND_MAX;
    
    int i, j;
    for(i=1;i<=3000;i++)
    {
        j = 1+(int)(10.0*rand()/RAND_MAX+1.0);
        printf("%3d", j);
        if(i%30==0)printf("\n");
    }
    
    return 0;
}