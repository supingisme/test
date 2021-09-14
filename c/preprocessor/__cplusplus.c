/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:39 CST. */
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
 *	__cplusplus
 *	This macro is defned when the C++ compiler is in use. You can use __
 *	cplusplus to test whether a header is compiled by a C compiler or a C++
 *	compiler. This macro is similar to __STDC_VERSION__, in that it expands to a
 *	version number. A fully conforming implementation of the 1998 C++ standard
 *	will defne this macro to 199711L. The GNU C++ compiler is not yet fully
 *	conforming, so it uses 1 instead. It is hoped to complete the implementation of
 *	standard C++ in the near future.
 */

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define print(...) printf(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

int main()
{



	return 0;
}
