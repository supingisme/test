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
 *	char * strdup (const char *s) [Function]
 *	This function copies the null-terminated string s into a newly allocated string. The
 *	string is allocated using malloc; see Section 3.2.2 [Unconstrained Allocation], page 33.
 *	If malloc cannot allocate space for the new string, strdup returns a null pointer.
 *	Otherwise it returns a pointer to the new string.
 *	wchar_t * wcsdup (const wchar t *ws) [Function]
 *	This function copies the null-terminated wide character string ws into a newly allo
 *	cated string. The string is allocated using malloc; see Section 3.2.2 [Unconstrained
 *	Allocation], page 33. If malloc cannot allocate space for the new string, wcsdup
 *	returns a null pointer. Otherwise it returns a pointer to the new wide character
 *	string.
 *	This function is a GNU extension.
 *	char * strndup (const char *s, size t size) [Function]
 *	This function is similar to strdup but always copies at most size characters into the
 *	newly allocated string.
 *	If the length of s is more than size, then strndup copies just the frst size characters
 *	and adds a closing null terminator. Otherwise all characters are copied and the string
 *	is terminated.
 *	This function is diﬀerent to strncpy in that it always terminates the destination
 *	string.
 *	strndup is a GNU extension.
 */
