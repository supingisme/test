/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:09 CST. */
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

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
 *	void assert_perror (int errnum) [Macro]
 *	Similar to assert, but verifes that errnum is zero.
 *	If NDEBUG is not defned, assert_perror tests the value of errnum. If it is nonzero,
 *	assert_perror aborts the program after printing a message of the form:
 *	‘file’:linenum: function: error text
 *	on the standard error stream. The fle name, line number, and function name are
 *	as for assert. The error text is the result of strerror (errnum). See Section 2.3
 *	[Error Messages], page 24.
 *	Like assert, if NDEBUG is defned before ‘assert.h’ is included, the assert_perror
 *	macro does absolutely nothing. It does not evaluate the argument, so errnum should
 *	not have any side eﬀects. It is best for errnum to be just a simple variable reference;
 *	often it will be errno.
 *	This macro is a GNU extension.
 */

#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	assert_perror(0);
}
