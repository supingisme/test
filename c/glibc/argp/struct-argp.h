/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:09 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	struct argp [Data Type]
 *	This structure specifes how to parse a given set of options and arguments, perhaps
 *	in conjunction with other argp parsers. It has the following felds:
 *	const struct argp_option *options
 *	A pointer to a vector of argp_option structures specifying which options
 *	this argp parser understands; it may be zero if there are no options at
 *	all. See Section 25.3.4 [Specifying Options in an Argp Parser], page 657.
 *	argp_parser_t parser
 *	A pointer to a function that defnes actions for this parser; it is called
 *	for each option parsed, and at other well-defned points in the parsing
 *	process. A value of zero is the same as a pointer to a function that always
 *	returns ARGP_ERR_UNKNOWN. See Section 25.3.5 [Argp Parser Functions],
 *	page 659.
 *	const char *args_doc
 *	If non-zero, a string describing what non-option arguments are called by
 *	this parser. This is only used to print the ‘Usage:’ message. If it contains
 *	newlines, the strings separated by them are considered alternative usage
 *	patterns and printed on separate lines. Lines after the frst are prefxed
 *	by ‘ or: ’ instead of ‘Usage:’.
 *	const char *doc
 *	If non-zero, a string containing extra text to be printed before and after
 *	the options in a long help message, with the two sections separated by a
 *	vertical tab (’\v’, ’\013’) character. By convention, the documentation
 *	before the options is just a short string explaining what the program does.
 *	Documentation printed after the options describe behavior in more detail.
 *	const struct argp_child *children
 *	A pointer to a vector of argp_children structures. This pointer specifes
 *	which additional argp parsers should be combined with this one. See
 *	Section 25.3.6 [Combining Multiple Argp Parsers], page 664.
 *	char *(*help_filter)(int key, const char *text, void *input)
 *	If non-zero, a pointer to a function that flters the output of help messages.
 *	See Section 25.3.8 [Customizing Argp Help Output], page 666.
 *	const char *argp_domain
 *	If non-zero, the strings used in the argp library are translated using the
 *	domain described by this string. If zero, the current default domain is
 *	used.
 */

#include <argp.h>

struct argp{
	const struct argp_option *options;
	argp_parser_t parser;
	const char *args_doc;
	const char *doc;
	const struct argp_child *children;
	char *(*help_filter)(int key, const char *text, void *input);
	const char *argp_domain;
};
