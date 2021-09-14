/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:40 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
/*
 *	__STDC_VERSION__
 *	This macro expands to the C Standard’s version number, a long integer constant
 *	of the form yyyymmL where yyyy and mm are the year and month of the
 *	Standard version. This signifes which version of the C Standard the compiler
 *	conforms to. Like __STDC__, this is not necessarily accurate for the entire
 *	implementation, unless GNU CPP is being used with GCC.
 *	The value 199409L signifes the 1989 C standard as amended in 1994, which
 *	is the current default; the value 199901L signifes the 1999 revision of the C
 *	standard. Support for the 1999 revision is not yet complete.
 *	This macro is not defned if the ‘-traditional-cpp’ option is used, nor when
 *	compiling C++ or Objective-C.
 */

#include <stdio.h>

int main()
{
	printf("%d, %d\n", __STDC_VERSION__, __STDC_HOSTED__);
};

/*
 *	$ gcc __STDC_VERSION__.c 
 *	__STDC_VERSION__.c: 在函数‘main’中:
 *	__STDC_VERSION__.c:19:17: 错误：‘__STDC_VERSION__’未声明(在此函数内第一次使用)
 *	  printf("%s\n", __STDC_VERSION__);
 *	                   ^
 *	                   __STDC_VERSION__.c:19:17: 附注：每个未声明的标识符在其出现的函数内只报告一次
 *	                   [RongTao@localhost preprocessor]$ gcc __STDC_VERSION__.c -traditional-cpp
 *	                   In file included from /usr/include/features.h:376:0,
 *	                                    from /usr/include/stdio.h:28,
 *	                                                     from __STDC_VERSION__.c:16:
 * /usr/include/sys/cdefs.h:31:3: 错误：#error "You need a ISO C conforming compiler to use the glibc head
ers" # error "You need a ISO C conforming compiler to use the glibc headers"
   ^

 */
