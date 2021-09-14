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
 *	void * memmove (void *to, const void *from, size t size) [Function]
 *	memmove copies the size bytes at from into the size bytes at to, even if those two
 *	blocks of space overlap. In the case of overlap, memmove is careful to copy the original
 *	values of the bytes in the block at from, including those bytes which also belong to
 *	the block at to.
 *	The value returned by memmove is the value of to.
 *	wchar_t * wmemmove (wchar *wto, const wchar t *wfrom, size t size) [Function]
 *	wmemmove copies the size wide characters at wfrom into the size wide characters at
 *	wto, even if those two blocks of space overlap. In the case of overlap, memmove is
 *	careful to copy the original values of the wide characters in the block at wfrom,
 *	including those wide characters which also belong to the block at wto.
 *
 *	The following is a possible implementation of wmemcpy but there are more optimiza
 *	tions possible.
 *	wchar_t *
 *	wmempcpy (wchar_t *restrict wto, const wchar_t *restrict wfrom,
 *	size_t size)
 *	{
 *	return (wchar_t *) mempcpy (wto, wfrom, size * sizeof (wchar_t));
 *	}
 *	The value returned by wmemmove is the value of wto.
 *	This function is a GNU extension.
 */
