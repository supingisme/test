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
 *	error_t argp_parse (const struct argp *argp, int argc, char **argv, [Function]
 *	unsigned flags, int *arg_index, void *input)
 *	The argp_parse function parses the arguments in argv, of length argc, using the argp
 *	parser argp. See Section 25.3.3 [Specifying Argp Parsers], page 656.
 *	A value of zero is the same as a struct argpcontaining all zeros. ﬂags is a set of
 *	ﬂag bits that modify the parsing behavior. See Section 25.3.7 [Flags for argp_parse],
 *	page 665. input is passed through to the argp parser argp, and has meaning defned
 *	by argp. A typical usage is to pass a pointer to a structure which is used for specifying
 *	parameters to the parser and passing back the results.
 *	Unless the ARGP_NO_EXIT or ARGP_NO_HELP ﬂags are included in ﬂags, calling argp_
 *	parse may result in the program exiting. This behavior is true if an error is detected,
 *	or when an unknown option is encountered. See Section 25.6 [Program Termination],
 *	page 684.
 *	If arg index is non-null, the index of the frst unparsed option in argv is returned as
 *	a value.
 *	The return value is zero for successful parsing, or an error code (see Section 2.2 [Error
 *	Codes], page 14) if an error is detected. Diﬀerent argp parsers may return arbitrary
 *	error codes, but the standard error codes are: ENOMEM if a memory allocation error
 *	occurred, or EINVAL if an unknown option or option argument is encountered.
 */

#include <argp.h>

/*
 *	error_t argp_parse (const struct argp *argp, int argc, char **argv,
 *						unsigned flags, int *arg_index, void *input)
 */

const char *argp_program_version =
"argp-ex2 1.0";
const char *argp_program_bug_address =
"<bug-gnu-utils@gnu.org>";
/* Program documentation. */
static char doc[] =
"Argp example #2 -- a pretty minimal program using argp";
/* Our argument parser. The options, parser, and
 * args_doc felds are zero because we have neither options or
 * arguments; doc and argp_program_bug_address will be
 * used in the output for ‘--help’, and the ‘--version’
 * option will print out argp_program_version. */
static struct argp argp = { 0, 0, 0, doc };


int main (int argc, char **argv)
{
	argp_parse (&argp, argc, argv, 0, 0, 0);
	exit (0);
}
