/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:15 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:10 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*
 *	struct mntent * getmntent (FILE *stream) [Function]
 *	The getmntent function takes as the parameter a fle handle previously returned by
 *	successful call to setmntent. It returns a pointer to a static variable of type struct
 *	mntent which is flled with the information from the next entry from the fle currently
 *	read.
 *	The fle format used prescribes the use of spaces or tab characters to separate the
 *	felds. This makes it harder to use name containing one of these characters (e.g.,
 *	mount points using spaces). Therefore these characters are encoded in the fles and
 *	the getmntent function takes care of the decoding while reading the entries back in.
 *	’\040’ is used to encode a space character, ’\011’ to encode a tab character, ’\012’
 *	to encode a newline character, and ’\\’ to encode a backslash.
 *	If there was an error or the end of the fle is reached the return value is NULL.
 *	This function is not thread-safe since all calls to this function return a pointer to
 *	the same static variable. getmntent_r should be used in situations where multiple
 *	threads access the fle.
 *	struct mntent * getmntent_r (FILE *stream, struct mentent [Function]
 *	*result, char *buffer, int bufsize)
 *	The getmntent_r function is the reentrant variant of getmntent. It also returns the
 *	next entry from the fle and returns a pointer. The actual variable the values are
 *	stored in is not static, though. Instead the function stores the values in the variable
 *	pointed to by the result parameter. Additional information (e.g., the strings pointed
 *	to by the elements of the result) are kept in the buﬀer of size bufsize pointed to by
 *	buﬀer.
 *	Escaped characters (space, tab, backslash) are converted back in the same way as it
 *	happens for getmentent.
 *	The function returns a NULL pointer in error cases. Errors could be:
 *	• error while reading the fle,
 *	• end of fle reached,
 *	• bufsize is too small for reading a complete new entry.
 */	

#include <mntent.h>


