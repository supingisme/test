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
 *	void assert (int expression) [Macro]
 *	Verify the programmer’s belief that expression is nonzero at this point in the program.
 *	If NDEBUG is not defned, assert tests the value of expression. If it is false (zero),
 *	assert aborts the program (see Section 25.6.4 [Aborting a Program], page 686) after
 *	printing a message of the form:
 *	‘file’:linenum: function: Assertion ‘expression’ failed.
 *	on the standard error stream stderr (see Section 12.2 [Standard Streams], page 226).
 *	The flename and line number are taken from the C preprocessor macros __FILE__
 *	and __LINE__ and specify where the call to assert was made. When using the
 *	GNU C compiler, the name of the function which calls assert is taken from the
 *	built-in variable __PRETTY_FUNCTION__; with older compilers, the function name and
 *	following colon are omitted.
 *	If the preprocessor macro NDEBUG is defned before ‘assert.h’ is included, the assert
 *	macro is defned to do absolutely nothing.
 *	Warning: Even the argument expression expression is not evaluated if NDEBUG is in
 *	eﬀect. So never use assert with arguments that involve side eﬀects. For example,
 *	assert (++i > 0); is a bad idea, because i will not be incremented if NDEBUG is
 *	defned.
 */

#include <assert.h>
#include <stdio.h>


#define debug() printf("%d\n", __LINE__)


int main()
{
	debug();

	assert(1);

	debug();

	//assert(0);

	debug();

	assert(-1);debug();
	assert(2);debug();
}
