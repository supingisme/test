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
 *	void * memcpy (void *restrict to, const void *restrict from, size t size) [Function]
 *	The memcpy function copies size bytes from the object beginning at from into the
 *	object beginning at to. The behavior of this function is undefned if the two arrays
 *	to and from overlap; use memmove instead if overlapping is possible.
 *	The value returned by memcpy is the value of to.
 *	Here is an example of how you might use memcpy to copy the contents of an array:
 *	struct foo *oldarray, *newarray;
 *	int arraysize;
 *	...
 *	memcpy (new, old, arraysize * sizeof (struct foo));
 *	wchar_t * wmemcpy (wchar t *restrict wto, const wchar t *restrict [Function]
 *	wfrom, size t size)
 *	The wmemcpy function copies size wide characters from the object beginning at wfrom
 *	into the object beginning at wto. The behavior of this function is undefned if the
 *	two arrays wto and wfrom overlap; use wmemmove instead if overlapping is possible.
 *	The following is a possible implementation of wmemcpy but there are more optimiza
 *	tions possible.
 *	wchar_t *
 *	wmemcpy (wchar_t *restrict wto, const wchar_t *restrict wfrom,
 *	size_t size)
 *	{
 *	return (wchar_t *) memcpy (wto, wfrom, size * sizeof (wchar_t));
 *	}
 *	The value returned by wmemcpy is the value of wto.
 *	This function was introduced in Amendment 1 to ISO C90.
 *
 *
 *
 *
 *	void * mempcpy (void *restrict to, const void *restrict from, size t [Function]
 *	size)
 *	The mempcpy function is nearly identical to the memcpy function. It copies size bytes
 *	from the object beginning at from into the object pointed to by to. But instead of
 *	returning the value of to it returns a pointer to the byte following the last written byte
 *	in the object beginning at to. I.e., the value is ((void *) ((char *) to + size)).
 *	This function is useful in situations where a number of objects shall be copied to
 *	consecutive memory positions.
 *	void *
 *	combine (void *o1, size_t s1, void *o2, size_t s2)
 *	{
 *	void *result = malloc (s1 + s2);
 *	if (result != NULL)
 *	mempcpy (mempcpy (result, o1, s1), o2, s2);
 *	return result;
 *	}
 *	This function is a GNU extension.
 *	wchar_t * wmempcpy (wchar t *restrict wto, const wchar t *restrict [Function]
 *	wfrom, size t size)
 *	The wmempcpy function is nearly identical to the wmemcpy function. It copies size
 *	wide characters from the object beginning at wfrom into the object pointed to by
 *	wto. But instead of returning the value of wto it returns a pointer to the wide
 *	character following the last written wide character in the object beginning at wto.
 *	I.e., the value is wto + size.
 *	This function is useful in situations where a number of objects shall be copied to
 *	consecutive memory positions.
 *	The following is a possible implementation of wmemcpy but there are more optimiza
 *	tions possible.
 *	wchar_t *
 *	wmempcpy (wchar_t *restrict wto, const wchar_t *restrict wfrom,
 *	size_t size)
 *	{
 *	return (wchar_t *) mempcpy (wto, wfrom, size * sizeof (wchar_t));
 *	}
 *	This function is a GNU extension.
 */
