/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
 *	void __va_copy (va list dest, va list src) [Macro]
 *	The __va_copy macro allows copying of objects of type va_list even if this is not
 *	an integral type. The argument pointer in dest is initialized to point to the same
 *	argument as the pointer in src.
 *	This macro is a GNU extension but it will hopefully also be available in the next
 *	update of the ISO C standard.
 */

#include <stdarg.h>

#include <stdio.h>

int fun(const char *fmt, ...)
{
	va_list ap, save;
	
#ifdef __va_copy
		__va_copy (save, ap);
#else
	save = ap;
#endif
	
}

int main()
{
	
}
