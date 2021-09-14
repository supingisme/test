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

int fesetexceptflag (const fexcept t *flagp, int excepts) [Function]
This function restores the ﬂags for the exceptions indicated by excepts to the values
stored in the variable pointed to by ﬂagp.
The function returns zero in case the operation was successful, a non-zero value oth
erwise.

 */

#include <fenv.h>
#include <stdio.h>
#include <math.h>

int execption_catch_handle(int raised)
{
    /* catch deal with */
	if (raised & FE_INEXACT) 
    { /* ... */ 
        printf("FE_INEXACT\n");
    }
    if (raised & FE_OVERFLOW) 
    { /* ... */ 
        printf("FE_OVERFLOW\n");
    }
	if (raised & FE_INVALID) 
    { /* ... */ 
        printf("FE_INVALID\n");
    }
    if (raised & FE_DIVBYZERO) 
    { /* ... */ 
        printf("FE_DIVBYZERO\n");
    }
    if (raised & FE_UNDERFLOW) 
    { /* ... */ 
        printf("FE_UNDERFLOW\n");
    }
}

int main()
{
	double f;
	int raised, i, j, excepts;
    
    fexcept_t exception;
    
    /* try */
	feclearexcept(FE_ALL_EXCEPT);
    
    /* throws */
    //feraiseexcept (FE_DIVBYZERO);
    
	f = sqrtf(-1);
    
    fegetexceptflag(&exception, FE_INEXACT |
                           FE_OVERFLOW | 
                           FE_INVALID | 
                           FE_DIVBYZERO |
                           FE_UNDERFLOW);
    /* 存在问题 */
    i = fesetexceptflag(&exception, excepts);
    
    printf("excepts = %d\n", excepts);
    
    /* catch */
	raised = fetestexcept (exception);
                           
    
    
    execption_catch_handle(raised);

	
	return 0;
}
