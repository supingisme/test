/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

/*	regex_t [Data Type]
 *	This type of object holds a compiled regular expression. It is actually a structure. It
 *	has just one feld that your programs should look at:
 *	re_nsub This feld holds the number of parenthetical subexpressions in the regular
 *	expression that was compiled.
 *	There are several other felds, but we don’t describe them here, because only the
 *	functions in the library should use them.
 *	After you create a regex_t object, you can compile a regular expression into it by calling
 *	regcomp.
 *
 *	int regcomp (regex t *restrict compiled, const char *restrict pattern, [Function]
 *	int cflags)
 *	The function regcomp “compiles” a regular expression into a data structure that you
 *	can use with regexec to match against a string. The compiled regular expression
 *	format is designed for efcient matching. regcomp stores it into *compiled.
 *	It’s up to you to allocate an object of type regex_t and pass its address to regcomp.
 *	The argument cﬂags lets you specify various options that control the syntax and
 *	semantics of regular expressions. See Section 10.3.2 [Flags for POSIX Regular Ex
 *	pressions], page 211.
 *	If you use the ﬂag REG_NOSUB, then regcomp omits from the compiled regular expres
 *	sion the information necessary to record how subexpressions actually match. In this
 *	case, you might as well pass 0 for the matchptr and nmatch arguments when you call
 *	regexec.
 *	If you don’t use REG_NOSUB, then the compiled regular expression does have the
 *	capacity to record how subexpressions match. Also, regcomp tells you how many
 *	subexpressions pattern has, by storing the number in compiled->re_nsub. You can
 *	use that value to decide how long an array to allocate to hold information about
 *	subexpression matches.
 *	regcomp returns 0 if it succeeds in compiling the regular expression; otherwise, it
 *	returns a nonzero error code (see the table below). You can use regerror to produce
 *	an error message string describing the reason for a nonzero value; see Section 10.3.6
 *	[POSIX Regexp Matching Cleanup], page 213.
 *
 *	Here are the possible nonzero values that regcomp can return:
 *	REG_BADBR
 *	There was an invalid ‘\{...\}’ construct in the regular expression. A valid
 *	‘\{...\}’ construct must contain either a single number, or two numbers in
 *	increasing order separated by a comma.
 *	REG_BADPAT
 *	There was a syntax error in the regular expression.
 *	REG_BADRPT
 *	A repetition operator such as ‘?’ or ‘*’ appeared in a bad position (with no
 *	preceding subexpression to act on).
 *	REG_ECOLLATE
 *	The regular expression referred to an invalid collating element (one not de
 *	fned in the current locale for string collation). See Section 7.3 [Categories of
 *	Activities that Locales Aﬀect], page 151.
 *	REG_ECTYPE
 *	The regular expression referred to an invalid character class name.
 *	REG_EESCAPE
 *	The regular expression ended with ‘\’.
 *	REG_ESUBREG
 *	There was an invalid number in the ‘\digit’ construct.
 *
 *	REG_EBRACK
 *	There were unbalanced square brackets in the regular expression.
 *	REG_EPAREN
 *	An extended regular expression had unbalanced parentheses, or a basic regular
 *	expression had unbalanced ‘\(’ and ‘\)’.
 *	REG_EBRACE
 *	The regular expression had unbalanced ‘\{’ and ‘\}’.
 *	REG_ERANGE
 *	One of the endpoints in a range expression was invalid.
 *	REG_ESPACE
 *	regcomp ran out of memory.
 *
 *
 */

int main()
{
	regex_t rt;

	int ret = regcomp(&rt, "{foo/}{, rong, tao}", REG_EXTENDED);



	return 0;
}
