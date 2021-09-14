/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
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
 *	6.9 Complex Numbers
 *	ISO C99 supports complex ﬂoating data types, and as an extension GCC supports them in
 *	C90 mode and in C++, and supports complex integer data types which are not part of ISO
 *	C99. You can declare complex types using the keyword _Complex. As an extension, the
 *	older GNU keyword __complex__ is also supported.
 *	For example, ‘_Complex double x;’ declares x as a variable whose real part and imagi
 *	nary part are both of type double. ‘_Complex short int y;’ declares y to have real and
 *	imaginary parts of type short int; this is not likely to be useful, but it shows that the set
 *	of complex types is complete.
 *	To write a constant with a complex data type, use the sufx ‘i’ or ‘j’ (either one; they are
 *	equivalent). For example, 2.5fi has type _Complex float and 3i has type _Complex int.
 *	Such a constant always has a pure imaginary value, but you can form any complex value
 *	you like by adding one to a real constant. This is a GNU extension; if you have an ISO
 *	C99 conforming C library (such as GNU libc), and want to construct complex constants of
 *	ﬂoating type, you should include <complex.h> and use the macros I or _Complex_I instead.
 *	To extract the real part of a complex-valued expression exp, write __real__ exp. Like
 *	wise, use __imag__ to extract the imaginary part. This is a GNU extension; for values of
 *	ﬂoating type, you should use the ISO C99 functions crealf, creal, creall, cimagf, cimag
 *	and cimagl, declared in <complex.h> and also provided as built-in functions by GCC.
 *	The operator ‘~’ performs complex conjugation when used on a value with a complex
 *	type. This is a GNU extension; for values of ﬂoating type, you should use the ISO C99
 *	functions conjf, conj and conjl, declared in <complex.h> and also provided as built-in
 *	functions by GCC.
 *	GCC can allocate complex automatic variables in a noncontiguous fashion; it’s even
 *	possible for the real part to be in a register while the imaginary part is on the stack (or
 *	vice-versa). Only the DWARF2 debug info format can represent this, so use of DWARF2 is
 *	recommended. If you are using the stabs debug info format, GCC describes a noncontiguous
 *	complex variable as if it were two separate variables of noncomplex type. If the variable’s
 *	actual name is foo, the two fctitious variables are named foo$real and foo$imag. You
 *	can examine and set these two fctitious variables with your debugger.
 */
