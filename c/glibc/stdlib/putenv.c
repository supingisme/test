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
 *	char * getenv (const char *name) [Function]
 *	This function returns a string that is the value of the environment variable name. You
 *	must not modify this string. In some non-Unix systems not using the GNU library,
 *	it might be overwritten by subsequent calls to getenv (but not by any other library
 *	function). If the environment variable name is not defned, the value is a null pointer.
 *
 *
 *
 *	int putenv (char *string) [Function]
 *	The putenv function adds or removes defnitions from the environment. If the string
 *	is of the form ‘name=value’, the defnition is added to the environment. Otherwise,
 *	the string is interpreted as the name of an environment variable, and any defnition
 *	for this variable in the environment is removed.
 *	The diﬀerence to the setenv function is that the exact string given as the parameter
 *	string is put into the environment. If the user should change the string after the
 *	putenv call this will reﬂect in automatically in the environment. This also requires
 *	that string is no automatic variable which scope is left before the variable is removed
 *	from the environment. The same applies of course to dynamically allocated variables
 *	which are freed later.
 *	This function is part of the extended Unix interface. Since it was also available in
 *	old SVID libraries you should defne either XOPEN SOURCE or SVID SOURCE
 *	before including any header.
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int main()
{
	putenv("RONGTAO=/home/RongTao/test/c");


	char *env = getenv("RONGTAO");

	printf("env = %s\n", env);

	//free(env);

	return 0;
}
