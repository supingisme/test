/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*
 *	25.4.2 Standard Environment Variables
 *	These environment variables have standard meanings. This doesn’t mean that they are
 *	always present in the environment; but if these variables are present, they have these
 *	meanings. You shouldn’t try to use these environment variable names for some other
 *	purpose.
 *	HOME
 *	This is a string representing the user’s home directory, or initial default working
 *	directory.
 *	The user can set HOME to any value. If you need to make sure to obtain the
 *	proper home directory for a particular user, you should not use HOME; instead,
 *	look up the user’s name in the user database (see Section 29.13 [User Database],
 *	page 745).
 *	For most purposes, it is better to use HOME, precisely because this lets the user
 *	specify the value.
 *	LOGNAME
 *	This is the name that the user used to log in. Since the value in the environment
 *	can be tweaked arbitrarily, this is not a reliable way to identify the user who
 *	is running a program; a function like getlogin (see Section 29.11 [Identifying
 *	Who Logged In], page 737) is better for that purpose.
 *	For most purposes, it is better to use LOGNAME, precisely because this lets the
 *	user specify the value.
 *	PATH
 *	A path is a sequence of directory names which is used for searching for a fle.
 *	The variable PATH holds a path used for searching for programs to be run.
 *	The execlp and execvp functions (see Section 26.5 [Executing a File], page 691)
 *	use this environment variable, as do many shells and other utilities which are
 *	implemented in terms of those functions.
 *	The syntax of a path is a sequence of directory names separated by colons. An
 *	empty string instead of a directory name stands for the current directory (see
 *	Section 14.1 [Working Directory], page 343).
 *	A typical value for this environment variable might be a string like:
 *	:/bin:/etc:/usr/bin:/usr/new/X11:/usr/new:/usr/local/bin
 *	This means that if the user tries to execute a program named foo, the system
 *	will look for fles named ‘foo’, ‘/bin/foo’, ‘/etc/foo’, and so on. The frst of
 *	these fles that exists is the one that is executed.
 *	TERM
 *	This specifes the kind of terminal that is receiving program output. Some
 *	programs can make use of this information to take advantage of special escape
 *	sequences or terminal modes supported by particular kinds of terminals. Many
 *	programs which use the termcap library (see Section “Finding a Terminal De
 *	scription” in The Termcap Library Manual) use the TERM environment variable,
 *	for example.
 *
 *	TZ
 *	This specifes the time zone. See Section 21.4.7 [Specifying the Time Zone with
 *	TZ], page 566, for information about the format of this string and how it is used.
 *	LANG
 *	This specifes the default locale to use for attribute categories where neither LC_
 *	ALL nor the specifc environment variable for that category is set. See Chapter 7
 *	[Locales and Internationalization], page 150, for more information about locales.
 *	LC_ALL
 *	If this environment variable is set it overrides the selection for all the locales
 *	done using the other LC_* environment variables. The value of the other LC_*
 *	environment variables is simply ignored in this case.
 *	LC_COLLATE
 *	This specifes what locale to use for string sorting.
 *	LC_CTYPE
 *	This specifes what locale to use for character sets and character classifcation.
 *	LC_MESSAGES
 *	This specifes what locale to use for printing messages and to parse responses.
 *	LC_MONETARY
 *	This specifes what locale to use for formatting monetary values.
 *	LC_NUMERIC
 *	This specifes what locale to use for formatting numbers.
 *	LC_TIME
 *	This specifes what locale to use for formatting date/time values.
 *	NLSPATH
 *	This specifes the directories in which the catopen function looks for message
 *	translation catalogs.
 *	_POSIX_OPTION_ORDER
*	If this environment variable is defned, it suppresses the usual reordering of com
*	mand line arguments by getopt and argp_parse. See Section 25.1.1 [Program
*	Argument Syntax Conventions], page 647.
 */
