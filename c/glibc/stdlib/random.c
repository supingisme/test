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
long int random (void) [Function]
This function returns the next pseudo-random number in the sequence. The value
returned ranges from 0 to RAND_MAX.
NB: Temporarily this function was defned to return a int32_t value to indicate that
the return value always contains 32 bits even if long int is wider. The standard
demands it diﬀerently. Users must always be aware of the 32-bit limitation, though.
void srandom (unsigned int seed) [Function]
The srandom function sets the state of the random number generator based on the
integer seed. If you supply a seed value of 1, this will cause random to reproduce the
default set of random numbers.
To produce a diﬀerent set of pseudo-random numbers each time your program runs,
do srandom (time (0)).
*/

#include <stdio.h>
#include <stdlib.h>



int main()
{
    RAND_MAX;
    
    srandom((int)time(0));
    
    int i, j;
    for(i=1;i<=3000;i++)
    {
        j = 1+(int)(10.0*random()/RAND_MAX+1.0);
        printf("%3d", j);
        if(i%30==0)printf("\n");
    }
    
    return 0;
}
