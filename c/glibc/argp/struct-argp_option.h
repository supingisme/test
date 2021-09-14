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
 *	struct argp_option [Data Type]
 *	This structure specifes a single option that an argp parser understands, as well as
 *	how to parse and document that option. It has the following felds:
 *	const char *name
 *	The long name for this option, corresponding to the long option ‘--name’;
 *	this feld may be zero if this option only has a short name. To specify
 *	multiple names for an option, additional entries may follow this one, with
 *	the OPTION_ALIAS ﬂag set. See Section 25.3.4.1 [Flags for Argp Options],
 *	page 658.
 *	int key The integer key provided by the current option to the option parser. If
 *	key has a value that is a printable ascii character (i.e., isascii (key)
 *	is true), it also specifes a short option ‘-char’, where char is the ascii
 *	character with the code key.
 *	const char *arg
 *	If non-zero, this is the name of an argument associated with this option,
 *	which must be provided (e.g., with the ‘--name=value’ or ‘-char value’
 *	syntaxes), unless the OPTION_ARG_OPTIONAL ﬂag (see Section 25.3.4.1
 *	[Flags for Argp Options], page 658) is set, in which case it may be pro
 *	vided.
 *	int flags Flags associated with this option, some of which are referred to above.
 *	See Section 25.3.4.1 [Flags for Argp Options], page 658.
 *	const char *doc
 *	A documentation string for this option, for printing in help messages.
 *	If both the name and key felds are zero, this string will be printed tabbed
 *	left from the normal option column, making it useful as a group header.
 *	This will be the frst thing printed in its group. In this usage, it’s con
 *	ventional to end the string with a ‘:’ character.
 *	int group Group identity for this option.
 *	In a long help message, options are sorted alphabetically within each
 *	group, and the groups presented in the order 0, 1, 2, . . ., n, −m, . . .,
 *	−2, −1.
 *	Every entry in an options array with this feld 0 will inherit the group
 *	number of the previous entry, or zero if it’s the frst one. If it’s a group
 *	header with name and key felds both zero, the previous entry + 1 is the
 *	default. Automagic options such as ‘--help’ are put into group −1.
 *	Note that because of C structure initialization rules, this feld often need
 *	not be specifed, because 0 is the correct value.
 */

#include <argp.h>


struct argp_option{
	const char *name;
	int key;
	const char *arg;
	int flags;
	const char *doc;
	int group;
};
