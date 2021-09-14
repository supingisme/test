/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
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

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
#include <stdio.h>
#include <stdlib.h>


#define max(a,b) \
	({ typeof (a) _a = (a); \
	 typeof (b) _b = (b); \
	 _a > _b ? _a : _b; })

struct A{
    int a;
};

#define _str(s) (#s)

int main()
{
    struct A a;
    
    printf("%s\n", _str(typeof(struct A*)));
    
    typeof(a) b;
    typeof(struct A) c;
    typeof(struct A) *d = malloc(sizeof(struct A));
    typeof(d) e = malloc(sizeof(struct A));
    
    b.a = 10;
    c.a = 10;
    d->a = 10;
    e->a = 10;
    
    __typeof__(a) f;
    
    return 0;
}
