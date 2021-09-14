/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:07 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	cleanup (cleanup_function)
 *	The cleanup attribute runs a function when the variable goes out of scope.
 *	This attribute can only be applied to auto function scope variables; it may not
 *	be applied to parameters or variables with static storage duration. The function
 *	must take one parameter, a pointer to a type compatible with the variable. The
 *	return value of the function (if any) is ignored.
 *	If ‘-fexceptions’ is enabled, then cleanup function will be run during the stack
 *	unwinding that happens during the processing of the exception. Note that the
 *	cleanup attribute does not allow the exception to be caught, only to perform
 *	an action. It is undefned what happens if cleanup function does not return
 *	normally.
 */

#include <stdio.h>

void clean_up()
{
	printf("clean up\n");
}

__attribute__((cleanup(clean_up)))void fun()
{
	printf("fun\n");
}

int main()
{
	fun();


	return 0;
}
