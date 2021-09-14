/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*	FILE * fdopen (int filedes, const char *opentype) [Function]
 *	The fdopen function returns a new stream for the fle descriptor fledes.
 *	The opentype argument is interpreted in the same way as for the fopen function (see
 *	Section 12.3 [Opening Streams], page 227), except that the ‘b’ option is not permitted;
 *	this is because GNU makes no distinction between text and binary fles. Also, "w"
 *	and "w+" do not cause truncation of the fle; these have an eﬀect only when opening
 *	a fle, and in this case the fle has already been opened. You must make sure that the
 *	opentype argument matches the actual mode of the open fle descriptor.
 *	The return value is the new stream. If the stream cannot be created (for example, if
 *	the modes for the fle indicated by the fle descriptor do not permit the access specifed
 *	by the opentype argument), a null pointer is returned instead.
 *	In some other systems, fdopen may fail to detect that the modes for fle descriptor
 *	do not permit the access specifed by opentype. The GNU C library always checks
 *	for this.
 *
 *
 *	int fileno (FILE *stream) [Function]
 *	This function returns the fle descriptor associated with the stream stream. If an
 *	error is detected (for example, if the stream is not valid) or if stream does not do I/O
 *	to a fle, fileno returns −1.
 *	int fileno_unlocked (FILE *stream) [Function]
 *	The fileno_unlocked function is equivalent to the fileno function except that it
 *	does not implicitly lock the stream if the state is FSETLOCKING_INTERNAL.
 *	This function is a GNU extension.
 *
 *
 *	int fclean (FILE *stream) [Function]
 *	Clean up the stream stream so that its buﬀer is empty. If stream is doing output,
 *	force it out. If stream is doing input, give the data in the buﬀer back to the system,
 *	arranging to reread it.
 */

