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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:52:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:23 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V "virbr0"

#define str1 "hello world"
#define str2 "hello world1"

int main()
{
	

	printf("%p:%p\n", str1, str2);
	printf("%d\n", str1 - str2);

    printf("%s:%d\n", V, strlen(V));

    FILE *fp = popen("ifconfig virbr0 | grep virbr0 | awk '{print $1}'", "r");

    char str[256];
    fgets(str, strlen(V)+1, fp);
    printf("%s:%d, %s:%d\n", V, strlen(V), str, strlen(str));

    return 0;
}
