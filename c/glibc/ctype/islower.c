/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
 *	int islower (int c) [Function]
 *	Returns true if c is a lower-case letter. The letter need not be from the Latin alphabet,
 *	any alphabet representable is valid.
 *	int isupper (int c) [Function]
 *	Returns true if c is an upper-case letter. The letter need not be from the Latin
 *	alphabet, any alphabet representable is valid.
 *	int isalpha (int c) [Function]
 *	Returns true if c is an alphabetic character (a letter). If islower or isupper is true
 *	of a character, then isalpha is also true.
 *	In some locales, there may be additional characters for which isalpha is true—letters
 *	which are neither upper case nor lower case. But in the standard "C" locale, there
 *	are no such additional characters.
 *	int isdigit (int c) [Function]
 *	Returns true if c is a decimal digit (‘0’ through ‘9’).
 *
 *	int isalnum (int c) [Function]
 *	Returns true if c is an alphanumeric character (a letter or number); in other words,
 *	if either isalpha or isdigit is true of a character, then isalnum is also true.
 *	int isxdigit (int c) [Function]
 *	Returns true if c is a hexadecimal digit. Hexadecimal digits include the normal
 *	decimal digits ‘0’ through ‘9’ and the letters ‘A’ through ‘F’ and ‘a’ through ‘f’.
 *	int ispunct (int c) [Function]
 *	Returns true if c is a punctuation character. This means any printing character that
 *	is not alphanumeric or a space character.
 *	int isspace (int c) [Function]
 *	Returns true if c is a whitespace character. In the standard "C" locale, isspace
 *	returns true for only the standard whitespace characters:
 *	’ ’ space
 *	’\f’ formfeed
 *	’\n’ newline
 *	’\r’ carriage return
 *	’\t’ horizontal tab
 *	’\v’ vertical tab
 *	int isblank (int c) [Function]
 *	Returns true if c is a blank character; that is, a space or a tab. This function was
 *	originally a GNU extension, but was added in ISO C99.
 *	int isgraph (int c) [Function]
 *	Returns true if c is a graphic character; that is, a character that has a glyph associated
 *	with it. The whitespace characters are not considered graphic.
 *	int isprint (int c) [Function]
 *	Returns true if c is a printing character. Printing characters include all the graphic
 *	characters, plus the space (‘ ’) character.
 *	int iscntrl (int c) [Function]
 *	Returns true if c is a control character (that is, a character that is not a printing
 *	character).
 *	int isascii (int c) [Function]
 *	Returns true if c is a 7-bit unsigned char value that fts into the US/UK ASCII
 *	character set. This function is a BSD extension and is also an SVID extension.
 *
 *
 */
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	printf("%c\n", argv[1][0]);
	char ch = argv[1][0];

	if(isalpha(ch))
		printf("isalpha\n");
	if(islower(ch))
		printf("islower\n");
	if(isupper(ch))
		printf("isupper\n");
	if(isdigit(ch))
		printf("isdigit\n");
	if(isalnum(ch))
		printf("isalnum\n");
	if(isxdigit(ch))
		printf("isxdigit\n");
	if(ispunct(ch))
		printf("ispunct\n");
	if(isspace(ch))
		printf("isspace\n");
	if(isblank(ch))
		printf("isblank\n");
	if(isgraph(ch))
		printf("isgraph\n");
	if(isprint(ch))
		printf("isprint\n");
	if(iscntrl(ch))
		printf("iscntrl\n");
	if(isascii(ch))
		printf("isascii\n");


	return 0;
}
