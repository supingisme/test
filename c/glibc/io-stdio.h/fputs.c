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
/*	int fputc (int c, FILE *stream) [Function]
 *	The fputc function converts the character c to type unsigned char, and writes it to
 *	the stream stream. EOF is returned if a write error occurs; otherwise the character c
 *	is returned.
 *	wint_t fputwc (wchar t wc, FILE *stream) [Function]
 *	The fputwc function writes the wide character wc to the stream stream. WEOF is
 *	returned if a write error occurs; otherwise the character wc is returned.
 *	int fputc_unlocked (int c, FILE *stream) [Function]
 *	The fputc_unlocked function is equivalent to the fputc function except that it does
 *	not implicitly lock the stream.
 *	wint_t fputwc_unlocked (wint t wc, FILE *stream) [Function]
 *	The fputwc_unlocked function is equivalent to the fputwc function except that it
 *	does not implicitly lock the stream.
 *	This function is a GNU extension.
 *	int putc (int c, FILE *stream) [Function]
 *	This is just like fputc, except that most systems implement it as a macro, making
 *	it faster. One consequence is that it may evaluate the stream argument more than
 *	once, which is an exception to the general rule for macros. putc is usually the best
 *	function to use for writing a single character.
 *	wint_t putwc (wchar t wc, FILE *stream) [Function]
 *	This is just like fputwc, except that it can be implement as a macro, making it faster.
 *	One consequence is that it may evaluate the stream argument more than once, which
 *	is an exception to the general rule for macros. putwc is usually the best function to
 *	use for writing a single wide character.
 *	int putc_unlocked (int c, FILE *stream) [Function]
 *	The putc_unlocked function is equivalent to the putc function except that it does
 *	not implicitly lock the stream.
 *
 *	wint_t putwc_unlocked (wchar t wc, FILE *stream) [Function]
 *	The putwc_unlocked function is equivalent to the putwc function except that it does
 *	not implicitly lock the stream.
 *	This function is a GNU extension.
 *	int putchar (int c) [Function]
 *	The putchar function is equivalent to putc with stdout as the value of the stream
 *	argument.
 *	wint_t putwchar (wchar t wc) [Function]
 *	The putwchar function is equivalent to putwc with stdout as the value of the stream
 *	argument.
 *	int putchar_unlocked (int c) [Function]
 *	The putchar_unlocked function is equivalent to the putchar function except that it
 *	does not implicitly lock the stream.
 *	wint_t putwchar_unlocked (wchar t wc) [Function]
 *	The putwchar_unlocked function is equivalent to the putwchar function except that
 *	it does not implicitly lock the stream.
 *	This function is a GNU extension.
 *	int fputs (const char *s, FILE *stream) [Function]
 *	The function fputs writes the string s to the stream stream. The terminating null
 *	character is not written. This function does not add a newline character, either. It
 *	outputs only the characters in the string.
 *	This function returns EOF if a write error occurs, and otherwise a non-negative value.
 *	For example:
 *	fputs ("Are ", stdout);
 *	fputs ("you ", stdout);
 *	fputs ("hungry?\n", stdout);
 *	outputs the text ‘Are you hungry?’ followed by a newline.
 *	int fputws (const wchar t *ws, FILE *stream) [Function]
 *	The function fputws writes the wide character string ws to the stream stream. The
 *	terminating null character is not written. This function does not add a newline
 *	character, either. It outputs only the characters in the string.
 *	This function returns WEOF if a write error occurs, and otherwise a non-negative value.
 *	int fputs_unlocked (const char *s, FILE *stream) [Function]
 *	The fputs_unlocked function is equivalent to the fputs function except that it does
 *	not implicitly lock the stream.
 *	This function is a GNU extension.
 *	int fputws_unlocked (const wchar t *ws, FILE *stream) [Function]
 *	The fputws_unlocked function is equivalent to the fputws function except that it
 *	does not implicitly lock the stream.
 *	This function is a GNU extension.
 *
 *	int puts (const char *s) [Function]
 *	The puts function writes the string s to the stream stdout followed by a newline.
*	The terminating null character of the string is not written. (Note that fputs does
		*	not write a newline as this function does.)
*	puts is the most convenient function for printing simple messages. For example:
*	puts ("This is a message.");
*	outputs the text ‘This is a message.’ followed by a newline.
*	int putw (int w, FILE *stream) [Function]
*	This function writes the word w (that is, an int) to stream. It is provided for com
*	patibility with SVID, but we recommend you use fwrite instead (see Section 12.11
*	[Block Input/Output], page 244).
*
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("rong.out", "w");

	fputs("Are you ok?", fp);

	return 0;
}
