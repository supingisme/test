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
 *	There is no way to solve this problem within the C standard, but you can use the GNU
 *	extension ‘#include_next’. It means, “Include the next fle with this name”. This directive
 *	works like ‘#include’ except in searching for the specifed fle: it starts searching the list
 *	of header fle directories after the directory in which the current fle was found.
 *	Suppose you specify ‘-I /usr/local/include’, and the list of directories to search
 *	also includes ‘/usr/include’; and suppose both directories contain ‘signal.h’. Ordinary
 *	#include <signal.h> fnds the fle under ‘/usr/local/include’. If that fle contains
 *	#include_next <signal.h>, it starts searching after that directory, and fnds the fle in
 *	‘/usr/include’.
 *	‘#include_next’ does not distinguish between <file> and "file" inclusion, nor does
 *	it check that the fle you specify has the same name as the current fle. It simply looks
 *	for the fle named, starting with the directory in the search path after the one where the
 *	current fle was found.
 *	The use of ‘#include_next’ can lead to great confusion. We recommend it be used
 *	only when there is no other alternative. In particular, it should not be used in the headers
 *	belonging to a specifc program; it should be used only to make global corrections along the
 *	lines of fixincludes.
 */

#include <stdio.h>

#include_next <once-only-header.h>

int main()
{
	printf("hello world\n");

	return 0;
}
