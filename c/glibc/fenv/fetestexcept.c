/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/**
 *	int feclearexcept (int excepts) [Function]
 *	This function clears all of the supported exception ﬂags indicated by excepts.
 *	The function returns zero in case the operation was successful, a non-zero value oth
 *	erwise.
 */

#include <fenv.h>
#include <stdio.h>
#include <math.h>

int feclearexcept(int except);

#define _flag printf("%d\n", flag);

int main()
{
	int flag = 99;

	flag = fetestexcept(FE_INEXACT);

	_flag

	flag = feraiseexcept(FE_INEXACT|FE_DIVBYZERO);

	_flag


	double f;
	int raised;
	feclearexcept (FE_ALL_EXCEPT);
    
	f = sqrtf(-1);
    
	raised = fetestexcept (FE_OVERFLOW | FE_INVALID | FE_UNDERFLOW);
	if (raised & FE_OVERFLOW) 
    { /* ... */ 
        printf("FE_OVERFLOW\n");
    }
	if (raised & FE_INVALID) 
    { /* ... */ 
        printf("FE_INVALID\n");
    }
    if (raised & FE_UNDERFLOW) 
    { /* ... */ 
        printf("FE_UNDERFLOW\n");
    }
	
	return 0;
}
