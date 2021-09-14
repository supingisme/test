/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:14 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:25 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 09:07:09 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:10 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*

int isinf (double x) [Function]
int isinff (ﬂoat x) [Function]
int isinfl (long double x) [Function]
This function returns -1 if x represents negative infnity, 1 if x represents positive
infnity, and 0 otherwise.

int isnan (double x) [Function]
int isnanf (ﬂoat x) [Function]
int isnanl (long double x) [Function]
This function returns a nonzero value if x is a “not a number” value, and zero other
wise.

int finite (double x) [Function]
int finitef (ﬂoat x) [Function]
int finitel (long double x)
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>


#define _print_(val) printf("%10s:%d\n", #val, val)


int main()
{
	float f, s;

	int i, tt;
	for(i=-5;i<5;i++)
	{
		f = 1.0/i;

		s = sqrtf(-1);

		if(isinf(f))
            printf(" isinf: %d\n", i);
        if(isinfl(f))
            printf("isinfl: %d\n", i);
        if(isinff(f))
            printf("isinff: %d\n", i);
        
        if(isnan(s))
            printf(" isnan: %d\n", i);
        if(isnanf(s))
            printf("isnanf: %d\n", i);
        if(isnanl(s))
            printf("isnanl: %d\n", i);
        
        if(finite(f))
            printf(" finite: %d\n", i);
        if(finitef(f))
            printf("finitef: %d\n", i);
        if(finitel(f))
            printf("finitel: %d\n", i);
	}

	return 0;
}
