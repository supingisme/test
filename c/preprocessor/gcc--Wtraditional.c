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
 *	10.4 Traditional warnings
 *	You can request warnings about features that did not exist, or worked diﬀerently, in tra
 *	ditional C with the ‘-Wtraditional’ option. GCC does not warn about features of ISO
 *	C which you must use when you are using a conforming compiler, such as the ‘#’ and ‘##’
 *	operators.
 *	Presently ‘-Wtraditional’ warns about:
 *	• Macro parameters that appear within string literals in the macro body. In traditional
 *	C macro replacement takes place within string literals, but does not in ISO C.
 *	• In traditional C, some preprocessor directives did not exist. Traditional preprocessors
 *	would only consider a line to be a directive if the ‘#’ appeared in column 1 on the line.
 *	Therefore ‘-Wtraditional’ warns about directives that traditional C understands but
 *	would ignore because the ‘#’ does not appear as the frst character on the line. It
 *	also suggests you hide directives like ‘#pragma’ not understood by traditional C by
 *	indenting them. Some traditional implementations would not recognize ‘#elif’, so it
 *	suggests avoiding it altogether.
 *	• A function-like macro that appears without an argument list. In some traditional
 *	preprocessors this was an error. In ISO C it merely means that the macro is not
 *	expanded.
 *	• The unary plus operator. This did not exist in traditional C.
 *	• The ‘U’ and ‘LL’ integer constant sufxes, which were not available in traditional C.
 *	(Traditional C does support the ‘L’ sufx for simple long integer constants.) You are not
 *	warned about uses of these sufxes in macros defned in system headers. For instance,
 *	UINT_MAX may well be defned as 4294967295U, but you will not be warned if you use
 *	UINT_MAX.
 *	You can usually avoid the warning, and the related warning about constants which
 *	are so large that they are unsigned, by writing the integer constant in question in
 *	hexadecimal, with no U sufx. Take care, though, because this gives the wrong result
 *	in exotic cases.
 */
