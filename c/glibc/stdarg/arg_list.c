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
#include <stdio.h>
#include <stdint.h>
#if 0
#ifndef _VALIST
#define _VALIST
typedef char *va_list;
#endif				/* _VALIST */
#endif

#define  _AUPBND            (sizeof (int ) - 1)
#define  _ADNBND            (sizeof (int ) - 1)

#define _bnd(X, bnd)        (((sizeof (X)) + (bnd)) & (~(bnd)))

#define va_arg(ap, T)       (*(T *)(((ap) += (_bnd (T, _AUPBND))) - (_bnd (T,_ADNBND))))
#define va_end(ap)          (void) 0
#define va_start(ap, A)     (void) ((ap) = (((char *) &(A)) + (_bnd (A,_AUPBND))))

int print(char *fmt, ...)
{
    char* args;
    
    va_start(args, fmt);
    
    int i;
    va_arg(i, int);
	
    printf("%s, %d\n", fmt, i);
    
    va_end(args);
    
    return 0;
}

int main()
{
    print("asdaaa", 5);
    
    return 0;
}
