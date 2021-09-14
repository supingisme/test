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
 *	__STDC__ In normal operation, this macro expands to the constant 1, to signify that this
 *	compiler conforms to ISO Standard C. If GNU CPP is used with a compiler
 *	other than GCC, this is not necessarily true; however, the preprocessor always
 *	conforms to the standard unless the ‘-traditional-cpp’ option is used.
 *	This macro is not defned if the ‘-traditional-cpp’ option is used.
 *	On some hosts, the system compiler uses a diﬀerent convention, where __STDC__
 *	is normally 0, but is 1 if the user specifes strict conformance to the C Standard.
 *	CPP follows the host convention when processing system header fles, but when
 *	processing user fles __STDC__ is always 1. This has been reported to cause
 *	problems; for instance, some versions of Solaris provide X Windows headers
 *	that expect __STDC__ to be either undefned or 1. See Chapter 12 [Invocation],
 *	page 55.
 */

#include <stdio.h>

int main()
{

	printf("%d\n", __STDC__);
}
