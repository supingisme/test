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
 *	size_t confstr (int parameter, char *buf, size t len) [Function]
 *	This function reads the value of a string-valued system parameter, storing the string
 *	into len bytes of memory space starting at buf. The parameter argument should be
 *	one of the ‘_CS_’ symbols listed below.
 *	The normal return value from confstr is the length of the string value that you asked
 *	for. If you supply a null pointer for buf, then confstr does not try to store the string;
 *	it just returns its length. A value of 0 indicates an error.
 *	If the string you asked for is too long for the buﬀer (that is, longer than len - 1),
 *	then confstr stores just that much (leaving room for the terminating null character).
 *	You can tell that this has happened because confstr returns a value greater than or
 *	equal to len.
 *	The following errno error conditions are defned for this function:
 *	EINVAL The value of the parameter is invalid.
 *
 *
 *	Currently there is just one parameter you can read with confstr:
 *	_CS_PATH This parameter’s value is the recommended default path for searching for ex
 *	ecutable fles. This is the path that a user has by default just after logging
 *	in.
 *	_CS_LFS_CFLAGS
 *	The returned string specifes which additional ﬂags must be given to the C
 *	compiler if a source is compiled using the _LARGEFILE_SOURCE feature select
 *	macro; see Section 1.3.4 [Feature Test Macros], page 7.
 *	_CS_LFS_LDFLAGS
 *	The returned string specifes which additional ﬂags must be given to the linker
 *	if a source is compiled using the _LARGEFILE_SOURCE feature select macro; see
 *	Section 1.3.4 [Feature Test Macros], page 7.
 *	_CS_LFS_LIBS
 *	The returned string specifes which additional libraries must be linked to the
 *	application if a source is compiled using the _LARGEFILE_SOURCE feature select
 *	macro; see Section 1.3.4 [Feature Test Macros], page 7.
 *	_CS_LFS_LINTFLAGS
 *	The returned string specifes which additional ﬂags must be given to the lint
 *	tool if a source is compiled using the _LARGEFILE_SOURCE feature select macro;
 *	see Section 1.3.4 [Feature Test Macros], page 7.
 *	_CS_LFS64_CFLAGS
 *	The returned string specifes which additional ﬂags must be given to the C
 *	compiler if a source is compiled using the _LARGEFILE64_SOURCE feature select
 *	macro; see Section 1.3.4 [Feature Test Macros], page 7.
 *	_CS_LFS64_LDFLAGS
 *	The returned string specifes which additional ﬂags must be given to the linker
 *	if a source is compiled using the _LARGEFILE64_SOURCE feature select macro;
 *	see Section 1.3.4 [Feature Test Macros], page 7.
 *	_CS_LFS64_LIBS
 *	The returned string specifes which additional libraries must be linked to the
 *	application if a source is compiled using the _LARGEFILE64_SOURCE feature
 *	select macro; see Section 1.3.4 [Feature Test Macros], page 7.
 *	_CS_LFS64_LINTFLAGS
 *	The returned string specifes which additional ﬂags must be given to the lint tool
 *	if a source is compiled using the _LARGEFILE64_SOURCE feature select macro;
 *	see Section 1.3.4 [Feature Test Macros], page 7.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char *get_default_path (void)
{
	size_t len = confstr (_CS_PATH, NULL, 0);
	char *buffer = (char *) malloc (len);
	if (confstr (_CS_PATH, buffer, len + 1) == 0)
	{
		free (buffer);
		return NULL;
	}
	return buffer;
}


int main()
{
	printf("%s\n", get_default_path());


	return 0;
}
