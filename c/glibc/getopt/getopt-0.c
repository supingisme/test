/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <getopt.h>
/*
$ ./a.out -c 3 -a 123 -b 123123
c: 3
a: 123
b: 123123
*/
int main(int argc, char **argv)
{

	char ch;
   
    while (1) 
    {
        switch(ch = getopt(argc, argv, "a:b:c:"))
        {
            case 'a':
                printf("a: %d\n", atoi(optarg));
                break;
            case 'b':
                printf("b: %d\n", atoi(optarg));
                break;
            case 'c':
                printf("c: %d\n", atoi(optarg));
                break;
            case -1:
                goto break_while;
                break;
            default:
                break;
        }
    }
break_while:
	
    return 0;
}
