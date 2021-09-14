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
 *	2.3 Search Path
 *	GCC looks in several diﬀerent places for headers. On a normal Unix system, if you do not
 *	instruct it otherwise, it will look for headers requested with #include <file> in:
 */usr/local/include
libdir/gcc/target/version/include
/usr/target/include
/usr/include
For C++ programs, it will also look in ‘/usr/include/g++-v3’, frst. In the above, target
is the canonical name of the system GCC was confgured to compile code for; often but not
always the same as the canonical name of the system it runs on. version is the version of
GCC in use.
You can add to this list with the ‘-Idir’ command line option. All the directories named
by ‘-I’ are searched, in left-to-right order, before the default directories. The only exception
is when ‘dir’ is already searched by default. In this case, the option is ignored and the
search order for system directories remains unchanged.
Duplicate directories are removed from the quote and bracket search chains before the
two chains are merged to make the fnal search chain. Thus, it is possible for a directory to
occur twice in the fnal search chain if it was specifed in both the quote and bracket chains.
You can prevent GCC from searching any of the default directories with the ‘-nostdinc’
option. This is useful when you are compiling an operating system kernel or some other
program that does not use the standard C library facilities, or the standard C library itself.
‘-I’ options are not ignored as described above when ‘-nostdinc’ is in eﬀect.
GCC looks for headers requested with #include "file" frst in the directory containing
the current fle, then in the directories as specifed by ‘-iquote’ options, then in the same
places it would have looked for a header requested with angle brackets. For example, if
‘/usr/include/sys/stat.h’ contains #include "types.h", GCC looks for ‘types.h’ frst
in ‘/usr/include/sys’, then in its usual search path.
‘#line’ (see Chapter 6 [Line Control], page 43) does not change GCC’s idea of the
directory containing the current fle.
You may put ‘-I-’ at any point in your list of ‘-I’ options. This has two eﬀects. First,
	directories appearing before the ‘-I-’ in the list are searched only for headers requested
 */
