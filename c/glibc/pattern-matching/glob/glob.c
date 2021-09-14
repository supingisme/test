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
#include <glob.h>
#include <fnmatch.h>

/*	glob_t [Data Type]
 *	This data type holds a pointer to a word vector. More precisely, it records both the
 *	address of the word vector and its size. The GNU implementation contains some
 *	more felds which are non-standard extensions.
 *	gl_pathc The number of elements in the vector, excluding the initial null entries if
 *	the GLOB DOOFFS ﬂag is used (see gl oﬀs below).
 *	gl_pathv The address of the vector. This feld has type char **.
 *	gl_offs The oﬀset of the frst real element of the vector, from its nominal address
 *	in the gl_pathv feld. Unlike the other felds, this is always an input to
 *	glob, rather than an output from it.
 *	If you use a nonzero oﬀset, then that many elements at the beginning
 *	of the vector are left empty. (The glob function flls them with null
 *	pointers.)
 *	The gl_offs feld is meaningful only if you use the GLOB_DOOFFS ﬂag.
 *	Otherwise, the oﬀset is always zero regardless of what is in this feld, and
 *	the frst real element comes at the beginning of the vector.
 *	gl_closedir
 *	The address of an alternative implementation of the closedir function.
 *	It is used if the GLOB_ALTDIRFUNC bit is set in the ﬂag parameter. The
 *	type of this feld is void (*) (void *).
 *	This is a GNU extension.
 *	gl_readdir
 *	The address of an alternative implementation of the readdir
 *	function used to read the contents of a directory. It is used if the
 *	GLOB_ALTDIRFUNC bit is set in the ﬂag parameter. The type of this feld
 *	is struct dirent *(*) (void *).
 *	This is a GNU extension.
 *	gl_opendir
 *	The address of an alternative implementation of the opendir function.
 *	It is used if the GLOB_ALTDIRFUNC bit is set in the ﬂag parameter. The
 *	type of this feld is void *(*) (const char *).
 *	This is a GNU extension.
 *	gl_stat The address of an alternative implementation of the stat function to get
 *	information about an object in the flesystem. It is used if the GLOB_
 *	ALTDIRFUNC bit is set in the ﬂag parameter. The type of this feld is
 *	int (*) (const char *, struct stat *).
 *	This is a GNU extension.
 *	gl_lstat The address of an alternative implementation of the lstat function to
 *	get information about an object in the flesystems, not following symbolic
 *	links. It is used if the GLOB_ALTDIRFUNC bit is set in the ﬂag parameter.
 *	The type of this feld is int (*) (const char *, struct stat *).
 *	This is a GNU extension.
 *
 *
 *	glob64_t [Data Type]
 *	This data type holds a pointer to a word vector. More precisely, it records both the
 *	address of the word vector and its size. The GNU implementation contains some
 *	more felds which are non-standard extensions.
 *	gl_pathc The number of elements in the vector, excluding the initial null entries if
 *	the GLOB DOOFFS ﬂag is used (see gl oﬀs below).
 *	gl_pathv The address of the vector. This feld has type char **.
 *	gl_offs The oﬀset of the frst real element of the vector, from its nominal address
 *	in the gl_pathv feld. Unlike the other felds, this is always an input to
 *	glob, rather than an output from it.
 *	If you use a nonzero oﬀset, then that many elements at the beginning
 *	of the vector are left empty. (The glob function flls them with null
 *	pointers.)
 *	The gl_offs feld is meaningful only if you use the GLOB_DOOFFS ﬂag.
 *	Otherwise, the oﬀset is always zero regardless of what is in this feld, and
 *	the frst real element comes at the beginning of the vector.
 *	gl_closedir
 *	The address of an alternative implementation of the closedir function.
 *	It is used if the GLOB_ALTDIRFUNC bit is set in the ﬂag parameter. The
 *	type of this feld is void (*) (void *).
 *	This is a GNU extension.
 *	gl_readdir
 *	The address of an alternative implementation of the readdir64 func
 *	tion used to read the contents of a directory. It is used if the GLOB_
 *	ALTDIRFUNC bit is set in the ﬂag parameter. The type of this feld is
 *	struct dirent64 *(*) (void *).
 *	This is a GNU extension.
*	gl_opendir
*	The address of an alternative implementation of the opendir function.
*	It is used if the GLOB_ALTDIRFUNC bit is set in the ﬂag parameter. The
*	type of this feld is void *(*) (const char *).
*	This is a GNU extension.
*	gl_stat The address of an alternative implementation of the stat64 function to
*	get information about an object in the flesystem. It is used if the GLOB_
*	ALTDIRFUNC bit is set in the ﬂag parameter. The type of this feld is
*	int (*) (const char *, struct stat64 *).
*	This is a GNU extension.
*	gl_lstat The address of an alternative implementation of the lstat64 function to
*	get information about an object in the flesystems, not following symbolic
*	links. It is used if the GLOB_ALTDIRFUNC bit is set in the ﬂag parameter.
*	The type of this feld is int (*) (const char *, struct stat64 *).
*	This is a GNU extension.
*
 *
 */

int main()
{
	glob_t result;

	int ret = glob("{foo/}{, bar, baz}", GLOB_BRACE, NULL, &result);

	printf("ret=%d\n", ret);

	return 0;
}
