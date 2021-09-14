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
/*	int fgetc (FILE *stream) [Function]
 *	This function reads the next character as an unsigned char from the stream stream
 *	and returns its value, converted to an int. If an end-of-fle condition or read error
 *	occurs, EOF is returned instead.
 *	wint_t fgetwc (FILE *stream) [Function]
 *	This function reads the next wide character from the stream stream and returns its
 *	value. If an end-of-fle condition or read error occurs, WEOF is returned instead.
 *	int fgetc_unlocked (FILE *stream) [Function]
 *	The fgetc_unlocked function is equivalent to the fgetc function except that it does
 *	not implicitly lock the stream.
 *	wint_t fgetwc_unlocked (FILE *stream) [Function]
 *	The fgetwc_unlocked function is equivalent to the fgetwc function except that it
 *	does not implicitly lock the stream.
 *	This function is a GNU extension.
 *	int getc (FILE *stream) [Function]
 *	This is just like fgetc, except that it is permissible (and typical) for it to be imple
 *	mented as a macro that evaluates the stream argument more than once. getc is often
 *	highly optimized, so it is usually the best function to use to read a single character.
 *
 *	wint_t getwc (FILE *stream) [Function]
 *	This is just like fgetwc, except that it is permissible for it to be implemented as
 *	a macro that evaluates the stream argument more than once. getwc can be highly
 *	optimized, so it is usually the best function to use to read a single wide character.
 *	int getc_unlocked (FILE *stream) [Function]
 *	The getc_unlocked function is equivalent to the getc function except that it does
 *	not implicitly lock the stream.
 *	wint_t getwc_unlocked (FILE *stream) [Function]
 *	The getwc_unlocked function is equivalent to the getwc function except that it does
 *	not implicitly lock the stream.
 *	This function is a GNU extension.
 *	int getchar (void) [Function]
 *	The getchar function is equivalent to getc with stdin as the value of the stream
 *	argument.
 *	wint_t getwchar (void) [Function]
 *	The getwchar function is equivalent to getwc with stdin as the value of the stream
 *	argument.
 *	int getchar_unlocked (void) [Function]
 *	The getchar_unlocked function is equivalent to the getchar function except that it
 *	does not implicitly lock the stream.
 *	wint_t getwchar_unlocked (void) [Function]
 *	The getwchar_unlocked function is equivalent to the getwchar function except that
 *	it does not implicitly lock the stream.
 *	This function is a GNU extension.
 *
 *	int getw (FILE *stream) [Function]
 *	This function reads a word (that is, an int) from stream. It’s provided for compat
 *	ibility with SVID. We recommend you use fread instead (see Section 12.11 [Block
 *	Input/Output], page 244). Unlike getc, any int value could be a valid result. getw
 *	returns EOF when it encounters end-of-fle or an error, but there is no way to distin
 *	guish this from an input word with value -1.
 */
#include <stdio.h>
#include <stdlib.h>

int
y_or_n_p (const char *question)
{
	fputs (question, stdout);
	while (1)
	{
		int c, answer;
		/* Write a space to separate answer from question. */
		fputc (' ', stdout);
		/* Read the frst character of the line.
		 * This should be the answer character, but might not be. */
		c = tolower (fgetc (stdin));
		answer = c;
		/* Discard rest of input line. */
		while (c != '\n' && c != EOF)
			c = fgetc (stdin);
		/* Obey the answer if it was valid. */
		if (answer == 'y')
			return 1;
		if (answer == 'n')
			return 0;
		/* Answer was invalid: ask for valid answer. */
		fputs ("Please answer y or n:", stdout);
	}
}

int main()
{
	printf("%s\n", 0 == y_or_n_p("Are you ok?")?"NO":"YES");

	return 0;
}
