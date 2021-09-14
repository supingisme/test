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
/*
 *	char * strcat (char *restrict to, const char *restrict from) [Function]
 *	The strcat function is similar to strcpy, except that the characters from from are
 *	concatenated or appended to the end of to, instead of overwriting it. That is, the
 *	frst character from from overwrites the null character marking the end of to.
 *	An equivalent defnition for strcat would be:
 *	char *
 *	strcat (char *restrict to, const char *restrict from)
 *	{
 *	strcpy (to + strlen (to), from);
 *	return to;
 *	}
 *	This function has undefned results if the strings overlap.
 *	wchar_t * wcscat (wchar t *restrict wto, const wchar t *restrict [Function]
 *	wfrom)
 *	The wcscat function is similar to wcscpy, except that the characters from wfrom are
 *	concatenated or appended to the end of wto, instead of overwriting it. That is, the
 *	frst character from wfrom overwrites the null character marking the end of wto.
 *	An equivalent defnition for wcscat would be:
 *	wchar_t *
 *	wcscat (wchar_t *wto, const wchar_t *wfrom)
 *	{
 *	wcscpy (wto + wcslen (wto), wfrom);
 *	return wto;
 *	}
 *
 *
 *	char * strncat (char *restrict to, const char *restrict from, size t [Function]
 *	size)
 *	This function is like strcat except that not more than size characters from from are
 *	appended to the end of to. A single null character is also always appended to to, so
 *	the total allocated size of to must be at least size + 1 bytes longer than its initial
 *	length.
 *	The strncat function could be implemented like this:
 *	char *
 *	strncat (char *to, const char *from, size_t size)
 *	{
 *	to[strlen (to) + size] = ’\0’;
 *	strncpy (to + strlen (to), from, size);
 *	return to;
 *	}
 *	The behavior of strncat is undefned if the strings overlap.
 *	wchar_t * wcsncat (wchar t *restrict wto, const wchar t *restrict [Function]
 *	wfrom, size t size)
 *	This function is like wcscat except that not more than size characters from from are
 *	appended to the end of to. A single null character is also always appended to to, so
 *	the total allocated size of to must be at least size + 1 bytes longer than its initial
 *	length.
 *	The wcsncat function could be implemented like this:
 *	wchar_t *
 *	wcsncat (wchar_t *restrict wto, const wchar_t *restrict wfrom,
 *	size_t size)
 *	{
 *	wto[wcslen (to) + size] = L’\0’;
 *	wcsncpy (wto + wcslen (wto), wfrom, size);
 *	return wto;
 *	}
 *	The behavior of wcsncat is undefned if the strings overlap.
 *	Here is an example showing the use of strncpy and strncat (the wide character version
 *	is equivalent). Notice how, in the call to strncat, the size parameter is computed to avoid
 *	overﬂowing the character array buffer.
 *	#include <string.h>
 *	#include <stdio.h>
 *	#define SIZE 10
 *	static char buffer[SIZE];
 *	main ()
 *	{
 *	strncpy (buffer, "hello", SIZE);
 *	puts (buffer);
 *	strncat (buffer, ", world", SIZE - strlen (buffer) - 1);
 *	puts (buffer);
*	}
*	The output produced by this program looks like:
*	hello
*	hello, wo
 */

#include <string.h>
#include <stdio.h>
#include <malloc.h>

int main()
{
#define SHOW() printf("%s\n", string);
	char string[1024] = {0};

	SHOW();

	strcat(string,  "rongtao ");
	SHOW();

	strcat(string, "shi");

	SHOW();

	return 0;
}
