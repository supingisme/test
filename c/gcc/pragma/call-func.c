/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	6.54.3 MeP Pragmas
 *	custom io_volatile (on|off)
 *	Overrides the command line option -mio-volatile for the current fle. Note
 *	that for compatibility with future GCC releases, this option should only be
 *	used once before any io variables in each fle.
 *	GCC coprocessor available registers
 *	Specifes which coprocessor registers are available to the register allocator. reg
 *	isters may be a single register, register range separated by ellipses, or comma
 *	separated list of those. Example:
 *	#pragma GCC coprocessor available $c0...$c10, $c28
 *	GCC coprocessor call_saved registers
 *	Specifes which coprocessor registers are to be saved and restored by any func
 *	tion using them. registers may be a single register, register range separated by
 *	ellipses, or comma-separated list of those. Example:
 *	#pragma GCC coprocessor call_saved $c4...$c6, $c31
 *	GCC coprocessor subclass ’(A|B|C|D)’ = registers
 *	Creates and defnes a register class. These register classes can be used by inline
 *	asm constructs. registers may be a single register, register range separated by
 *	ellipses, or comma-separated list of those. Example:
 *	#pragma GCC coprocessor subclass ’B’ = $c2, $c4, $c6
 *	asm ("cpfoo %0" : "=B" (x));
 *	GCC disinterrupt name , name ...
 *	For the named functions, the compiler adds code to disable interrupts for the
 *	duration of those functions. Any functions so named, which are not encountered
 *	in the source, cause a warning that the pragma was not used. Examples:
 *	#pragma disinterrupt foo
 *	#pragma disinterrupt bar, grill
 *	int foo () { ... }
 *	GCC call name , name ...
 *	For the named functions, the compiler always uses a register-indirect call model
 *	when calling the named functions. Examples:
 *	extern int foo ();
 *	#pragma call foo
 */

#include <stdio.h>

int foo()
{
	printf("helloworld\n");
}

int main()
{
	#pragma custom io_volatile(on)

	#pragma call foo()

	return 0;
}
