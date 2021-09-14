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
/*	int printf (const char *template, . . .) [Function]
 *	The printf function prints the optional arguments under the control of the template
 *	string template to the stream stdout. It returns the number of characters printed,
 *	or a negative value if there was an output error.
 *	int wprintf (const wchar t *template, . . .) [Function]
 *	The wprintf function prints the optional arguments under the control of the wide
 *	template string template to the stream stdout. It returns the number of wide char
 *	acters printed, or a negative value if there was an output error.
 *	int fprintf (FILE *stream, const char *template, . . .) [Function]
 *	This function is just like printf, except that the output is written to the stream
 *	stream instead of stdout.
 *	int fwprintf (FILE *stream, const wchar t *template, . . .) [Function]
 *	This function is just like wprintf, except that the output is written to the stream
 *	stream instead of stdout.
 *	int sprintf (char *s, const char *template, . . .) [Function]
 *	This is like printf, except that the output is stored in the character array s instead
 *	of written to a stream. A null character is written to mark the end of the string.
 *
 *	The sprintf function returns the number of characters stored in the array s, not
 *	including the terminating null character.
 *	The behavior of this function is undefned if copying takes place between objects that
 *	overlap—for example, if s is also given as an argument to be printed under control of
 *	the ‘%s’ conversion. See Section 5.4 [Copying and Concatenation], page 77.
 *	Warning: The sprintf function can be dangerous because it can potentially output
 *	more characters than can ft in the allocation size of the string s. Remember that the
 *	feld width given in a conversion specifcation is only a minimum value.
 *	To avoid this problem, you can use snprintf or asprintf, described below.
 *	int swprintf (wchar t *s, size t size, const wchar t *template, . . .) [Function]
 *	This is like wprintf, except that the output is stored in the wide character array ws
 *	instead of written to a stream. A null wide character is written to mark the end of the
 *	string. The size argument specifes the maximum number of characters to produce.
 *	The trailing null character is counted towards this limit, so you should allocate at
 *	least size wide characters for the string ws.
 *	The return value is the number of characters generated for the given input, excluding
 *	the trailing null. If not all output fts into the provided buﬀer a negative value is
 *	returned. You should try again with a bigger output string. Note: this is diﬀerent
 *	from how snprintf handles this situation.
 *	Note that the corresponding narrow stream function takes fewer parameters.
 *	swprintf in fact corresponds to the snprintf function. Since the sprintf function
 *	can be dangerous and should be avoided the ISO C committee refused to make the
 *	same mistake again and decided to not defne an function exactly corresponding to
 *	sprintf.
 *	int snprintf (char *s, size t size, const char *template, . . .) [Function]
 *	The snprintf function is similar to sprintf, except that the size argument specifes
 *	the maximum number of characters to produce. The trailing null character is counted
 *	towards this limit, so you should allocate at least size characters for the string s.
 *	The return value is the number of characters which would be generated for the given
 *	input, excluding the trailing null. If this value is greater or equal to size, not all
 *	characters from the result have been stored in s. You should try again with a bigger
 *	output string. Here is an example of doing this:
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <malloc.h>

/* Construct a message describing the value of a variable
 * whose name is name and whose value is value. */
char *
make_message (char *name, char *value)
{
	/* Guess we need no more than 100 chars of space. */
	int size = 100;
	char *buffer = (char *) malloc (size);
	int nchars;
	if (buffer == NULL)
		return NULL;
	/* Try to print in the allocated space. */
	nchars = snprintf (buffer, size, "value of %s is %s",
			name, value);
	if (nchars >= size)
	{
		/* Reallocate buﬀer now that we know
		 * how much space is needed. */
		size = nchars + 1;
		buffer = (char *) realloc (buffer, size);
		if (buffer != NULL)
			/* Try again. */
			snprintf (buffer, size, "value of %s is %s",
					name, value);
	}
	/* The last call worked, return the string. */
	return buffer;
}

int main()
{
	wchar_t wc[] = L"Hello World";
	char c[] = {"rong tao"};

	printf("%s, %s\n", wc, c);
	wprintf(L"%s, %s\n",wc, c);

	printf("%s\n", make_message("RongTao", ":100score"));

	return 0;
}
