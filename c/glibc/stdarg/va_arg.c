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
 *	void va_start (va list ap, last-required) [Macro]
 *	This macro initializes the argument pointer variable ap to point to the frst of the
 *	optional arguments of the current function; last-required must be the last required
 *	argument to the function.
 *	See Section A.2.3.1 [Old-Style Variadic Functions], page 805, for an alternate defni
 *	tion of va_start found in the header fle ‘varargs.h’.
 *
 *	type va_arg (va list ap, type) [Macro]
 *	The va_arg macro returns the value of the next optional argument, and modifes the
 *	value of ap to point to the subsequent argument. Thus, successive uses of va_arg
 *	return successive optional arguments.
 *	The type of the value returned by va_arg is type as specifed in the call. type must
 *	be a self-promoting type (not char or short int or float) that matches the type of
 *	the actual argument.
 *
 *
 *	void va_end (va list ap) [Macro]
 *	This ends the use of ap. After a va_end call, further va_arg calls with the same ap
 *	may not work. You should invoke va_end before returning from the function in which
 *	va_start was invoked with the same ap argument.
 *	In the GNU C library, va_end does nothing, and you need not ever use it except for
 *	reasons of portability.
 */

#include <stdarg.h>
#include <stdio.h>

void fun (const char *fmt, ...)
{
	va_list arg;
	va_start(arg, fmt);
	
	vprintf(fmt, arg);

	va_end(arg);
}


int main()
{
	fun("RongTao%s\n", "helloadf");
}
