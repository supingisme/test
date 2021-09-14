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
 *	char * strcpy (char *restrict to, const char *restrict from) [Function]
 *	This copies characters from the string from (up to and including the terminating null
 *	character) into the string to. Like memcpy, this function has undefned results if the
 *	strings overlap. The return value is the value of to.
 *	wchar_t * wcscpy (wchar t *restrict wto, const wchar t *restrict [Function]
 *	wfrom)
 *	This copies wide characters from the string wfrom (up to and including the terminat
 *	ing null wide character) into the string wto. Like wmemcpy, this function has undefned
 *	results if the strings overlap. The return value is the value of wto.
 *	char * strncpy (char *restrict to, const char *restrict from, size t [Function]
 *	size)
 *	This function is similar to strcpy but always copies exactly size characters into to.
 *	If the length of from is more than size, then strncpy copies just the frst size charac
 *	ters. Note that in this case there is no null terminator written into to.
 *	If the length of from is less than size, then strncpy copies all of from, followed by
 *	enough null characters to add up to size characters in all. This behavior is rarely
 *	useful, but it is specifed by the ISO C standard.
 *	The behavior of strncpy is undefned if the strings overlap.
 *	Using strncpy as opposed to strcpy is a way to avoid bugs relating to writing past
 *	the end of the allocated space for to. However, it can also make your program much
 *	slower in one common case: copying a string which is probably small into a potentially
 *	large buﬀer. In this case, size may be large, and when it is, strncpy will waste a
 *	considerable amount of time copying null characters.
 *	wchar_t * wcsncpy (wchar t *restrict wto, const wchar t *restrict [Function]
 *	wfrom, size t size)
 *	This function is similar to wcscpy but always copies exactly size wide characters into
 *	wto.
 *	If the length of wfrom is more than size, then wcsncpy copies just the frst size wide
 *	characters. Note that in this case there is no null terminator written into wto.
 *	If the length of wfrom is less than size, then wcsncpy copies all of wfrom, followed by
 *	enough null wide characters to add up to size wide characters in all. This behavior
 *	is rarely useful, but it is specifed by the ISO C standard.
 *	The behavior of wcsncpy is undefned if the strings overlap.
 *	Using wcsncpy as opposed to wcscpy is a way to avoid bugs relating to writing past
 *	the end of the allocated space for wto. However, it can also make your program
 *	much slower in one common case: copying a string which is probably small into a
 *	potentially large buﬀer. In this case, size may be large, and when it is, wcsncpy will
 *	waste a considerable amount of time copying null wide characters.
 */
