/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:07 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	format (archetype, string-index, first-to-check)
 *	The format attribute specifes that a function takes printf, scanf, strftime
 *	or strfmon style arguments which should be type-checked against a format
 *	string. For example, the declaration:
 *	extern int
 *	my_printf (void *my_object, const char *my_format, ...)
 *	__attribute__ ((format (printf, 2, 3)));
 *	causes the compiler to check the arguments in calls to my_printf for consistency
 *	with the printf style format string argument my_format.
 *	The parameter archetype determines how the format string is interpreted, and
 *	should be printf, scanf, strftime, gnu_printf, gnu_scanf, gnu_strftime
 *	or strfmon. (You can also use __printf__, __scanf__, __strftime__ or __
 *	strfmon__.) On MinGW targets, ms_printf, ms_scanf, and ms_strftime are
 *	also present. archtype values such as printf refer to the formats accepted by
 *	the system’s C run-time library, while gnu_ values always refer to the formats
 *	accepted by the GNU C Library. On Microsoft Windows targets, ms_ values
 *	refer to the formats accepted by the ‘msvcrt.dll’ library. The parameter
 *	string-index specifes which argument is the format string argument (starting
 *	from 1), while frst-to-check is the number of the frst argument to check against
 *	the format string. For functions where the arguments are not available to be
 *	checked (such as vprintf), specify the third parameter as zero. In this case the
 *	compiler only checks the format string for consistency. For strftime formats,
 *	the third parameter is required to be zero. Since non-static C++ methods have
 *	an implicit this argument, the arguments of such methods should be counted
 *	from two, not one, when giving values for string-index and frst-to-check.
 *	In the example above, the format string (my_format) is the second argument
 *	of the function my_print, and the arguments to check start with the third
 *	argument, so the correct parameters for the format attribute are 2 and 3.
 *	The format attribute allows you to identify your own functions which take
 *	format strings as arguments, so that GCC can check the calls to these functions
 *	for errors. The compiler always (unless ‘-ffreestanding’ or ‘-fno-builtin’
 *	is used) checks formats for the standard library functions printf, fprintf,
 *	sprintf, scanf, fscanf, sscanf, strftime, vprintf, vfprintf and vsprintf
 *	whenever such warnings are requested (using ‘-Wformat’), so there is no need
 *	to modify the header fle ‘stdio.h’. In C99 mode, the functions snprintf,
 *	vsnprintf, vscanf, vfscanf and vsscanf are also checked. Except in strictly
 *	conforming C standard modes, the X/Open function strfmon is also checked
 *	as are printf_unlocked and fprintf_unlocked. See Section 3.4 [Options
 *	Controlling C Dialect], page 28.
 *	The target may provide additional types of format checks. See Section 6.53
 *	[Format Checks Specifc to Particular Target Machines], page 553.
 */
#include <stdio.h>
#include <stdarg.h>

int error(const char *fmt, const char *err, ...) __attribute__((format (printf, 1, 3)));

int __attribute__((format (printf, 1, 3)))  error(const char *fmt, const char *err, ...)
{
	va_list arg;
	va_start(arg, fmt);
	printf("%s: ", err);

	vprintf(fmt, arg);

	va_end(arg);
}

int rte_log(uint32_t level, uint32_t logtype, const char *format, ...)
#ifdef __GNUC__
#if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 2))
		__attribute__((cold))
#endif
#endif
		__attribute__((format(printf, 3, 4)));

int main()
{
	error("%d, %d, %d\n", "Not this kind of type", 1,3,4);

	return 0;
}
