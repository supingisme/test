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
 *	see in ../utmp folder
 *
 *
 *	void setutxent (void) [Function]
 *	This function is similar to setutent. On the GNU system it is simply an alias for
 *	setutent.
 *	struct utmpx * getutxent (void) [Function]
 *	The getutxent function is similar to getutent, but returns a pointer to a struct
 *	utmpx instead of struct utmp. On the GNU system it simply is an alias for getutent.
 *	void endutxent (void) [Function]
 *	This function is similar to endutent. On the GNU system it is simply an alias for
 *	endutent.
 *	struct utmpx * getutxid (const struct utmpx *id) [Function]
 *	This function is similar to getutid, but uses struct utmpx instead of struct utmp.
 *	On the GNU system it is simply an alias for getutid.
 *	struct utmpx * getutxline (const struct utmpx *line) [Function]
 *	This function is similar to getutid, but uses struct utmpx instead of struct utmp.
 *	On the GNU system it is simply an alias for getutline.
 *	struct utmpx * pututxline (const struct utmpx *utmp) [Function]
 *	The pututxline function is functionally identical to pututline, but uses struct
 *	utmpx instead of struct utmp. On the GNU system, pututxline is simply an alias
 *	for pututline.
 *	int utmpxname (const char *file) [Function]
 *	The utmpxname function is functionally identical to utmpname. On the GNU system,
 *	utmpxname is simply an alias for utmpname.
 *	You can translate between a traditional struct utmp and an XPG struct utmpx with
 *	the following functions. On the GNU system, these functions are merely copies, since the
 *	two structures are identical.
 *	int getutmp (const struct utmpx *utmpx, struct utmp *utmp) [Function]
 *	getutmp copies the information, insofar as the structures are compatible, from utmpx
 *	to utmp.
 *	int getutmpx (const struct utmp *utmp, struct utmpx *utmpx) [Function]
 *	getutmpx copies the information, insofar as the structures are compatible, from utmp
 *	to utmpx.
 *	
 *
 */

#include <stdio.h>
#include <utmpx.h>

int main()
{


	return 0;
}
