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
 *	-Wall Turns on all optional warnings which are desirable for normal code. At present
 *	this is ‘-Wcomment’, ‘-Wtrigraphs’, ‘-Wmultichar’ and a warning about integer
 *	promotion causing a change of sign in #if expressions. Note that many of the
 *	preprocessor’s warnings are on by default and have no options to control them.
 *
 *
 *	-Wcomment
 *	-Wcomments
 *	Warn whenever a comment-start sequence ‘/ *’ appears in a ‘/ *’ comment, or
 *	whenever a backslash-newline appears in a ‘//’ comment. (Both forms have
 *	the same eﬀect.)
 *	-Wtrigraphs
 *	Most trigraphs in comments cannot aﬀect the meaning of the program. How
 *	ever, a trigraph that would form an escaped newline (‘??/’ at the end of a line)
 *	can, by changing where the comment begins or ends. Therefore, only trigraphs
 *	that would form escaped newlines produce warnings inside a comment.
 *	This option is implied by ‘-Wall’. If ‘-Wall’ is not given, this option
 *	is still enabled unless trigraphs are enabled. To get trigraph conversion
 *	without warnings, but get the other ‘-Wall’ warnings, use ‘-trigraphs -Wall
 *	-Wno-trigraphs’.
 *	-Wtraditional
 *	Warn about certain constructs that behave diﬀerently in traditional and ISO C.
 *	Also warn about ISO C constructs that have no traditional C equivalent, and
 *	problematic constructs which should be avoided. See Chapter 10 [Traditional
 *	Mode], page 47.
 *	-Wundef Warn whenever an identifer which is not a macro is encountered in an ‘#if’
 *	directive, outside of ‘defined’. Such identifers are replaced with zero.
 *	-Wunused-macros
 *	Warn about macros defned in the main fle that are unused. A macro is used if
 *	it is expanded or tested for existence at least once. The preprocessor will also
 *	warn if the macro has not been used at the time it is redefned or undefned.
 *	Built-in macros, macros defned on the command line, and macros defned in
 *	include fles are not warned about.
 *	Note: If a macro is actually used, but only used in skipped conditional blocks,
 *	then CPP will report it as unused. To avoid the warning in such a case, you
 *	might improve the scope of the macro’s defnition by, for example, moving it
 *	into the frst skipped block. Alternatively, you could provide a dummy use with
 *	something like:
 *	#if defined the_macro_causing_the_warning
 *	#endif
 *	-Wendif-labels
 *	Warn whenever an ‘#else’ or an ‘#endif’ are followed by text. This usually
 *	happens in code of the form
 *	#if FOO
 *	...
 *	#else FOO
 *	...
 *	#endif FOO
 *	The second and third FOO should be in comments, but often are not in older
 *	programs. This warning is on by default.
 *	-Werror Make all warnings into hard errors. Source code which triggers warnings will
 *	be rejected.
 *	-Wsystem-headers
 *	Issue warnings for code in system headers. These are normally unhelpful in
 *	fnding bugs in your own code, therefore suppressed. If you are responsible for
 *	the system library, you may want to see them.
 *	-w Suppress all warnings, including those which GNU CPP issues by default.
 */

