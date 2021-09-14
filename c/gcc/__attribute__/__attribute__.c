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
 *	6.29 Declaring Attributes of Functions
 *	In GNU C, you declare certain things about functions called in your program which help
 *	the compiler optimize function calls and check your code more carefully.
 *	The keyword __attribute__ allows you to specify special attributes when making
 *	a declaration. This keyword is followed by an attribute specifcation inside double
 *	parentheses. The following attributes are currently defned for functions on all targets:
 *	aligned, alloc_size, noreturn, returns_twice, noinline, noclone, always_inline,
 *	flatten, pure, const, nothrow, sentinel, format, format_arg, no_instrument_
 *	function, section, constructor, destructor, used, unused, deprecated, weak, malloc,
 *	alias, warn_unused_result, nonnull, gnu_inline, externally_visible, hot, cold,
 *	artificial, error and warning. Several other attributes are defned for functions
 *	on particular target systems. Other attributes, including section are supported for
 *	variables declarations (see Section 6.36 [Variable Attributes], page 329) and for types (see
 *	Section 6.37 [Type Attributes], page 337).
 *	GCC plugins may provide their own attributes.
 *
 *
 *	You may also specify attributes with ‘__’ preceding and following each keyword. This
 *	allows you to use them in header fles without being concerned about a possible macro of
 *	the same name. For example, you may use __noreturn__ instead of noreturn.
 *	See Section 6.30 [Attribute Syntax], page 324, for details of the exact syntax for using
 *	attributes.
 *	alias ("target")
 *	The alias attribute causes the declaration to be emitted as an alias for another
 *	symbol, which must be specifed. For instance,
 *	
 */
