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
#include <stdlib.h>
#include <string.h>

int main()
{
    wchar_t str[] = L"Rong Tao say hello\n";
    
    char str2[10] = {'e','d','c','b','a'};
    
    printf("%s, %d, %d\n", &str, strlen((char*)str), sizeof(str));
    printf("%s, %d, %d\n", &str, wcslen(str), sizeof(str));
    printf("%s, %d, %d\n", &str, wcsnlen(str, 4), sizeof(str));
    printf("%s, %d, %d\n", &str2, strlen((char*)str2), sizeof(str2));
    printf("%s, %d, %d\n", &str2, strnlen((char*)str2, 3), sizeof(str2));

	char *s = NULL;

	if(s && strlen(s) > 0)
		printf("%d\n", strlen(s));

    return 0;
}   
