/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:37 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:37 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:21 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
#include <stdio.h>
#include <stdlib.h>


#define RED   "\033[31m"
#define GREEN "\x1b[32m"
#define CLEAR "\x1b[0m"


#define DEBUG_CHECK "\xe2\x9c\x92"
#define SUCCESS_CHECK "\xe2\x9c\x94"
#define FAILURE_CHECK "\xe2\x9c\x98"
#define 

int main()
{
    fprintf(stderr, "%s\n", DEBUG_CHECK);
    fprintf(stderr, "\xe2\x9c\x92\n");
    fprintf(stderr, "\xe2\x9c\x93\n");
    fprintf(stderr, "\xe2\x9c\x94\n");
    fprintf(stderr, "\xe2\x9c\x95\n");
    fprintf(stderr, "\xe2\x9c\x96\n");
    fprintf(stderr, "\xe2\x9c\x97\n");
    fprintf(stderr, "\xe2\x9c\x98\n");
    fprintf(stderr, "\xe2\x9c\x99\n");
    
    fprintf(stderr, RED "123123" FAILURE_CHECK " %s\n" CLEAR, "RongTao");
    fprintf(stderr, "############");
    fprintf(stderr, RED "123123" SUCCESS_CHECK " %s\n" CLEAR, "RongTao");
    fprintf(stderr, "############");
    return 0;
}