/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:14 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:25 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:55 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#define dir	"a/b/c/d/e/f/g/h/i/"

int main(const int argc, const char *argv[])
{
	/*
    printf("%s\n", argv[1]);
    printf("%s\n", dirname(argv[1]));
	printf("%s\n", dirname(dirname(argv[1])));    
	*/
	/*
	printf("%s\n%s\n%s\n%s\n",
			dirname(dir),
			dirname(dirname(dir)),
			dirname(dirname(dirname(dir))),
			dirname(dirname(dirname(dirname(dir)))));
			*/

	char str[250] = {"a/b/c/d/e/f/j/h/i/j/k"};

	printf("%s: %s\n", str, dirname(str));
	printf("%s: %s\n", str, dirname(str));
	printf("%s: %s\n", str, dirname(str));

    return 0;
}   
