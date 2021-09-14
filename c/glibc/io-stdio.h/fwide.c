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
/*	int fwide (FILE *stream, int mode) [Function]
 *	The fwide function can be used to set and query the state of the orientation of the
 *	stream stream. If the mode parameter has a positive value the streams get wide
 *	oriented, for negative values narrow oriented. It is not possible to overwrite previous
 *	orientations with fwide. I.e., if the stream stream was already oriented before the
 *	call nothing is done.
 *	If mode is zero the current orientation state is queried and nothing is changed.
 *	The fwide function returns a negative value, zero, or a positive value if the stream is
 *	narrow, not at all, or wide oriented respectively.
 *	This function was introduced in Amendment 1 to ISO C90 and is declared in
 *	‘wchar.h’.
 *	It is generally a good idea to orient a stream as early as possible. This can prevent
 *	surprise especially for the standard streams stdin, stdout, and stderr. If some library
 *	function in some situations uses one of these streams and this use orients the stream in a
 *	diﬀerent way the rest of the application expects it one might end up with hard to reproduce
 *	errors. Remember that no errors are signal if the streams are used incorrectly. Leaving
 *	a stream unoriented after creation is normally only necessary for library functions which
 *	create streams which can be used in diﬀerent contexts.
 *	When writing code which uses streams and which can be used in diﬀerent contexts it
 *	is important to query the orientation of the stream before using it (unless the rules of the
 *	library interface demand a specifc orientation). The following little, silly function illustrates
 *	this.
 *	void print_f (FILE *fp)
 *	{
 *		if (fwide (fp, 0) > 0)
			//Positive return value means wide orientation. 
			fputwc (L’f’, fp);
		else
			fputc (’f’, fp);
	}
 */
#include <stdio.h>
#include <wchar.h>

void
print_f (FILE *fp)
{
	if (fwide (fp, 0) > 0)
		/* Positive return value means wide orientation. */
		fputwc (L'f', fp);
	else
		fputc ('F', fp);
}

int main()
{
	FILE *fp = fopen("rong.out", "w");

	print_f(fp);

	return 0;
}
