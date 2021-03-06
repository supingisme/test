/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:40 CST. */
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
 *	3.6 Variadic Macros
 *	A macro can be declared to accept a variable number of arguments much as a function can.
 *	The syntax for defning the macro is similar to that of a function. Here is an example:
 *	#define eprintf(...) fprintf (stderr, __VA_ARGS__)
 *	This kind of macro is called variadic. When the macro is invoked, all the tokens in its
 *	argument list after the last named argument (this macro has none), including any commas,
 *	become the variable argument. This sequence of tokens replaces the identifer __VA_ARGS__
 *	in the macro body wherever it appears. Thus, we have this expansion:
 *	eprintf ("%s:%d: ", input_file, lineno)
 *	7! fprintf (stderr, "%s:%d: ", input_file, lineno)
 *	The variable argument is completely macro-expanded before it is inserted into the macro
 *	expansion, just like an ordinary argument. You may use the ‘#’ and ‘##’ operators to
 *	stringify the variable argument or to paste its leading or trailing token with another token.
 *	(But see below for an important special case for ‘##’.)
 *	If your macro is complicated, you may want a more descriptive name for the variable
 *	argument than __VA_ARGS__. CPP permits this, as an extension. You may write an argu
 *	ment name immediately before the ‘...’; that name is used for the variable argument. The
 *	eprintf macro above could be written
 *	#define eprintf(args...) fprintf (stderr, args)
 *	using this extension. You cannot use __VA_ARGS__ and this extension in the same macro.
 *	You can have named arguments as well as variable arguments in a variadic macro. We
 *	could defne eprintf like this, instead:
 *	#define eprintf(format, ...) fprintf (stderr, format, __VA_ARGS__)
 *	This formulation looks more descriptive, but unfortunately it is less ﬂexible: you must now
 *	supply at least one argument after the format string. In standard C, you cannot omit the
 *	comma separating the named argument from the variable arguments. Furthermore, if you
 *	leave the variable argument empty, you will get a syntax error, because there will be an
 *	extra comma after the format string.
 *	eprintf("success!\n", );
 *	7! fprintf(stderr, "success!\n", );
 *	GNU CPP has a pair of extensions which deal with this problem. First, you are allowed
 *	to leave the variable argument out entirely:
 *	eprintf ("success!\n")
 *	7! fprintf(stderr, "success!\n", );
 *	Second, the ‘##’ token paste operator has a special meaning when placed between a comma
 *	and a variable argument. If you write
 *	#define eprintf(format, ...) fprintf (stderr, format, ##__VA_ARGS__)
 *	and the variable argument is left out when the eprintf macro is used, then the comma
 *	before the ‘##’ will be deleted. This does not happen if you pass an empty argument, nor
 *	does it happen if the token preceding ‘##’ is anything other than a comma.
 *	eprintf ("success!\n")
 *	7! fprintf(stderr, "success!\n");
 *	The above explanation is ambiguous about the case where the only macro parameter is a
 *	variable arguments parameter, as it is meaningless to try to distinguish whether no argument
 *	at all is an empty argument or a missing argument. In this case the C99 standard is clear
 *	that the comma must remain, however the existing GCC extension used to swallow the
 *	comma. So CPP retains the comma when conforming to a specifc C standard, and drops
 *	it otherwise.
 *	C99 mandates that the only place the identifer __VA_ARGS__ can appear is in the re
 *	placement list of a variadic macro. It may not be used as a macro name, macro argument
 *	name, or within a diﬀerent type of macro. It may also be forbidden in open text; the
 *	standard is ambiguous. We recommend you avoid using it except for its defned purpose.
 *	Variadic macros are a new feature in C99. GNU CPP has supported them for a long
 *	time, but only with a named variable argument (‘args...’, not ‘...’ and __VA_ARGS__).
 *	If you are concerned with portability to previous versions of GCC, you should use only
 *	named variable arguments. On the other hand, if you are concerned with portability to
 *	other conforming implementations of C99, you should use only __VA_ARGS__.
 *	Previous versions of CPP implemented the comma-deletion extension much more gener
 *	ally. We have restricted it in this release to minimize the diﬀerences from C99. To get the
 *	same eﬀect with both this and previous versions of GCC, the token preceding the special
 *	‘##’ must be a comma, and there must be white space between that comma and whatever
 *	comes immediately before it:
 *	#define eprintf(format, args...) fprintf (stderr, format , ##args)
 *	See Section 11.4 [Diﬀerences from previous versions], page 54, for the gory details.
 */


#include <stdio.h>

#define print1(fmt, ...) printf(fmt, __VA_ARGS__)
#define print2(fmt, ...) printf(fmt, ##__VA_ARGS__)

int main()
{
	printf("hello, %s %s\n", "rong", "tao");
	print2("hello, %s %s\n", "rong", "tao");
}















