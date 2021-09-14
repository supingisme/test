/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:26 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:31 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:02 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:15 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdint.h>

#define       INT8 int8_t
#define      INT16 int16_t
#define      INT32 int32_t
#define      INT64 int64_t


#define _(a) _##a

#define E_V(T)      _(T) = sizeof(T)
#define T_V(T)      T _(T)
#define T(V)        typeof(V)
#define vtos(s)     #s

#define TYPE_N      3


enum{
    _(INT8), /* _INT8 */
    _(INT16),
    _(INT32),
    _(INT64),
    e_max,
};

struct Type_s{
	T_V(INT8); /* int8_t _INT8; */
	T_V(INT16);
	T_V(INT32);
	T_V(INT64);
    
}__attribute__((packed)) ;

static char *stype[] = {
vtos(INT8), /* "INT8" */
vtos(INT16),
vtos(INT32),
vtos(INT64),
NULL   
};

int finds(const char* str)
{
    int i;
    for(i=0;i<e_max;i++)
        if(strcmp(str, stype[i]) == 0)
            return i;
    return -1;
}

void show()
{
    int j = 0;
    while(stype[j++] != NULL)
        printf("%s\n", stype[j-1]);
}


int main()
{
    show();
    printf("%d\n", finds("INT64"));
    
    //printf("%d\n", sizeof(typeof(Type._uint8_t)));
    
	return 0;
}
