/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:13 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:55 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*	int vprintf (const char *template, va list ap) [Function]
 *	This function is similar to printf except that, instead of taking a variable number
 *	of arguments directly, it takes an argument list pointer ap.
 *	int vwprintf (const wchar t *template, va list ap) [Function]
 *	This function is similar to wprintf except that, instead of taking a variable number
 *	of arguments directly, it takes an argument list pointer ap
 *
 *	int vfprintf (FILE *stream, const char *template, va list ap) [Function]
 *	This is the equivalent of fprintf with the variable argument list specifed directly as
 *	for vprintf.
 *	int vfwprintf (FILE *stream, const wchar t *template, va list ap) [Function]
 *	This is the equivalent of fwprintf with the variable argument list specifed directly
 *	as for vwprintf.
 *	int vsprintf (char *s, const char *template, va list ap) [Function]
 *	This is the equivalent of sprintf with the variable argument list specifed directly as
 *	for vprintf.
 *	int vswprintf (wchar t *s, size t size, const wchar t *template, [Function]
 *	va list ap)
 *	This is the equivalent of swprintf with the variable argument list specifed directly
 *	as for vwprintf.
 *	int vsnprintf (char *s, size t size, const char *template, va list ap) [Function]
 *	This is the equivalent of snprintf with the variable argument list specifed directly
 *	as for vprintf.
 *	int vasprintf (char **ptr, const char *template, va list ap) [Function]
 *	The vasprintf function is the equivalent of asprintf with the variable argument
 *	list specifed directly as for vprintf.
 *	int obstack_vprintf (struct obstack *obstack, const char [Function]
 *	*template, va list ap)
 *	The obstack_vprintf function is the equivalent of obstack_printf with the variable
 *	argument list specifed directly as for vprintf.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void
eprintf (const char *template, ...)
{
	va_list ap;
	extern char *program_invocation_short_name;
	fprintf (stderr, "%s: ", program_invocation_short_name);
	va_start (ap, template);
	vfprintf (stderr, template, ap);
	va_end (ap);
}

int main()
{
	eprintf("rong:%s\n", "tao");
	
	return 0;
}
