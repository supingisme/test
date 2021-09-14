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
 *	FILE * setmntent (const char *file, const char *mode) [Function]
 *	The setmntent function prepares the fle named FILE which must be in the format
 *	of a ‘fstab’ and ‘mtab’ fle for the upcoming processing through the other functions
 *	of the family. The mode parameter can be chosen in the way the opentype parameter
 *	for fopen (see Section 12.3 [Opening Streams], page 227) can be chosen. If the fle is
 *	opened for writing the fle is also allowed to be empty.
 *	If the fle was successfully opened setmntent returns a fle descriptor for future use.
 *	Otherwise the return value is NULL and errno is set accordingly.
 *	int endmntent (FILE *stream) [Function]
 *	This function takes for the stream parameter a fle handle which previously was
 *	returned from the setmntent call. endmntent closes the stream and frees all resources.
 *	The return value is 1 unless an error occurred in which case it is 0.
 */
