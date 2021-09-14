/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:37 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:37 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:09 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:21 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
/*
 *	int iswctype (wint t wc, wctype t desc) [Function]
 *	This function returns a nonzero value if wc is in the character class specifed by desc.
 *	desc must previously be returned by a successful call to wctype.
 *	This function is declared in ‘wctype.h’.
 *	To make it easier to use the commonly-used classifcation functions, they are defned in
 *	the C library. There is no need to use wctype if the property string is one of the known
 *	character classes. In some situations it is desirable to construct the property strings, and
 *	then it is important that wctype can also handle the standard classes.
 *	int iswalnum (wint t wc) [Function]
 *	This function returns a nonzero value if wc is an alphanumeric character (a letter or
 *	number); in other words, if either iswalpha or iswdigit is true of a character, then
 *	iswalnum is also true.
 *	This function can be implemented using
 *	iswctype (wc, wctype ("alnum"))
 *	It is declared in ‘wctype.h’.
 *	int iswalpha (wint t wc) [Function]
 *	Returns true if wc is an alphabetic character (a letter). If iswlower or iswupper is
 *	true of a character, then iswalpha is also true.
 *	In some locales, there may be additional characters for which iswalpha is true—
 *	letters which are neither upper case nor lower case. But in the standard "C" locale,
 *	there are no such additional characters.
 *	This function can be implemented using
 *
 *	iswctype (wc, wctype ("alpha"))
 *	It is declared in ‘wctype.h’.
 *	int iswcntrl (wint t wc) [Function]
 *	Returns true if wc is a control character (that is, a character that is not a printing
 *	character).
 *	This function can be implemented using
 *	iswctype (wc, wctype ("cntrl"))
 *	It is declared in ‘wctype.h’.
 *	int iswdigit (wint t wc) [Function]
 *	Returns true if wc is a digit (e.g., ‘0’ through ‘9’). Please note that this function
 *	does not only return a nonzero value for decimal digits, but for all kinds of digits.
 *	A consequence is that code like the following will not work unconditionally for wide
 *	characters:
 *	n = 0;
 *	while (iswdigit (*wc))
 *	{
 *	n *= 10;
 *	n += *wc++ - L’0’;
 *	}
 *	This function can be implemented using
 *	iswctype (wc, wctype ("digit"))
 *	It is declared in ‘wctype.h’.
 *	int iswgraph (wint t wc) [Function]
 *	Returns true if wc is a graphic character; that is, a character that has a glyph asso
 *	ciated with it. The whitespace characters are not considered graphic.
 *	This function can be implemented using
 *	iswctype (wc, wctype ("graph"))
 *	It is declared in ‘wctype.h’.
 *	int iswlower (wint t wc) [Function]
 *	Returns true if wc is a lower-case letter. The letter need not be from the Latin
 *	alphabet, any alphabet representable is valid.
 *	This function can be implemented using
 *	iswctype (wc, wctype ("lower"))
 *	It is declared in ‘wctype.h’.
 *	int iswprint (wint t wc) [Function]
 *	Returns true if wc is a printing character. Printing characters include all the graphic
 *	characters, plus the space (‘ ’) character.
 *	This function can be implemented using
 *	iswctype (wc, wctype ("print"))
 *	It is declared in ‘wctype.h’.
 *	int iswpunct (wint t wc) [Function]
 *	Returns true if wc is a punctuation character. This means any printing character
 *	that is not alphanumeric or a space character.
 *	This function can be implemented using
 *	iswctype (wc, wctype ("punct"))
 *	It is declared in ‘wctype.h’.
 *	int iswspace (wint t wc) [Function]
*	Returns true if wc is a whitespace character. In the standard "C" locale, iswspace
*	returns true for only the standard whitespace characters:
*	L’ ’ space
*	L’\f’ formfeed
*	L’\n’ newline
*	L’\r’ carriage return
*	L’\t’ horizontal tab
*	L’\v’ vertical tab
*	This function can be implemented using
*	iswctype (wc, wctype ("space"))
*	It is declared in ‘wctype.h’.
*	int iswupper (wint t wc) [Function]
*	Returns true if wc is an upper-case letter. The letter need not be from the Latin
*	alphabet, any alphabet representable is valid.
*	This function can be implemented using
*	iswctype (wc, wctype ("upper"))
*	It is declared in ‘wctype.h’.
*	int iswxdigit (wint t wc) [Function]
*	Returns true if wc is a hexadecimal digit. Hexadecimal digits include the normal
*	decimal digits ‘0’ through ‘9’ and the letters ‘A’ through ‘F’ and ‘a’ through ‘f’.
*	This function can be implemented using
*	iswctype (wc, wctype ("xdigit"))
*	It is declared in ‘wctype.h’.
*	The GNU C library also provides a function which is not defned in the ISO C standard
*	but which is available as a version for single byte characters as well.
*	int iswblank (wint t wc) [Function]
*	Returns true if wc is a blank character; that is, a space or a tab. This function was
*	originally a GNU extension, but was added in ISO C99. It is declared in ‘wchar.h’.
*
 */
