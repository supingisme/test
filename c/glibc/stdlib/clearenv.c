/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
 *	int setenv (const char *name, const char *value, int replace) [Function]
 *	The setenv function can be used to add a new defnition to the environment. The
 *	entry with the name name is replaced by the value ‘name=value’. Please note that
 *	this is also true if value is the empty string. To do this a new string is created and the
 *	strings name and value are copied. A null pointer for the value parameter is illegal.
 *	If the environment already contains an entry with key name the replace parameter
 *	controls the action. If replace is zero, nothing happens. Otherwise the old entry is
 *	replaced by the new one.
 *	Please note that you cannot remove an entry completely using this function.
 *	This function was originally part of the BSD library but is now part of the Unix
 *	standard.
 *
 *
 *	int unsetenv (const char *name) [Function]
 *	Using this function one can remove an entry completely from the environment. If the
 *	environment contains an entry with the key name this whole entry is removed. A call
 *	to this function is equivalent to a call to putenv when the value part of the string is
 *	empty.
 *	The function return -1 if name is a null pointer, points to an empty string, or points
 *	to a string containing a = character. It returns 0 if the call succeeded.
 *	This function was originally part of the BSD library but is now part of the Unix
 *	standard. The BSD version had no return value, though.
 *
 *
 *	int clearenv (void) [Function]
 *	The clearenv function removes all entries from the environment. Using putenv and
 *	setenv new entries can be added again later.
 *	If the function is successful it returns 0. Otherwise the return value is nonzero.
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
	setenv("RongTao", "/home/RongTao/test/c/libc", 1);

	char *env = getenv("RongTao");

	printf("env = %s\n",  env);

	unsetenv("RongTao");

	printf("clearenv = %d\n", clearenv());


	return 0;
}
