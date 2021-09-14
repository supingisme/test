/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:39 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
/*
 *	-D name Predefne name as a macro, with defnition 1.
 *	-D name=definition
 *	The contents of defnition are tokenized and processed as if they appeared dur
 *	ing translation phase three in a ‘#define’ directive. In particular, the defnition
 *	will be truncated by embedded newline characters.
 *	If you are invoking the preprocessor from a shell or shell-like program you may
 *	need to use the shell’s quoting syntax to protect characters such as spaces that
 *	have a meaning in the shell syntax.
 *	If you wish to defne a function-like macro on the command line, write its
 *	argument list with surrounding parentheses before the equals sign (if any).
 *	Parentheses are meaningful to most shells, so you will need to quote the option.
 *	With sh and csh, ‘-D’name(args...)=definition’’ works.
 *	‘-D’ and ‘-U’ options are processed in the order they are given on the command
 *	line. All ‘-imacros file’ and ‘-include file’ options are processed after all
 *	‘-D’ and ‘-U’ options.
 */

#include <stdio.h>

int main()
{
/*
 *	$ gcc defined.c -D RongTao
 *	$ ./a.out
 */
#if defined(RongTao)
	printf("RongTao\n");
#endif
}
