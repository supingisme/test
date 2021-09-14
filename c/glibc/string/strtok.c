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
#include <stdio.h>
#include <string.h>

int main()
{
    char str[200] = {"Hello World! My name is Rong tao."};
    
    char *p = strtok(str, "owl");
    
    printf("%s, %p\n", str, str);
    printf("%s, %p\n", p, p);
    
    char str2[200] = {"Hello World! My name is Rong tao."};
    char *save_ptr;
    char *p2 = strtok_r(str2, "R", &save_ptr);
    
    printf("%s, %p\n", str2, str2);
    printf("%s, %p\n", p2, p2);
    printf("%s, %p, %p\n", save_ptr, save_ptr);
    
    return 0;
}   