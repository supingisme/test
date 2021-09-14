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

int isfinite (ﬂoat-type x) [Macro]
This macro returns a nonzero value if x is fnite: not plus or minus infnity, and not
NaN. It is equivalent to
(fpclassify (x) != FP_NAN && fpclassify (x) != FP_INFINITE)
isfinite is implemented as a macro which accepts any ﬂoating-point type.
int isnormal (ﬂoat-type x) [Macro]
This macro returns a nonzero value if x is fnite and normalized. It is equivalent to
(fpclassify (x) == FP_NORMAL)
int isnan (ﬂoat-type x) [Macro]
This macro returns a nonzero value if x is NaN. It is equivalent to
(fpclassify (x) == FP_NAN)

 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>


#define _print_(val) printf("%10s:%d\n", #val, val)


int main()
{
	float f;

	int i, tt;
	for(i=-5;i<5;i++)
	{
		f = 1.0/i;
		if(isfinite(f))
            printf("isfinite: %d\n", i);
        if(isnormal(f))
            printf("isnormal: %d\n", i);
        if(isnan(f))
            printf("   isnan: %d\n", i);
	}

	_print_(FP_NAN);
	_print_(FP_INFINITE);
	_print_(FP_ZERO);
	_print_(FP_SUBNORMAL);
	_print_(FP_NORMAL);

	return 0;
}
