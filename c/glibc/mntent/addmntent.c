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
 *	int addmntent (FILE *stream, const struct mntent *mnt) [Function]
 *	The addmntent function allows adding a new entry to the fle previously opened with
 *	setmntent. The new entries are always appended. I.e., even if the position of the
 *	fle descriptor is not at the end of the fle this function does not overwrite an existing
 *	entry following the current position.
 *	The implication of this is that to remove an entry from a fle one has to create a new
 *	fle while leaving out the entry to be removed and after closing the fle remove the
 *	old one and rename the new fle to the chosen name.
 *	This function takes care of spaces and tab characters in the names to be written to
 *	the fle. It converts them and the backslash character into the format describe in the
 *	getmntent description above.
 *	This function returns 0 in case the operation was successful. Otherwise the return
 *	value is 1 and errno is set appropriately.
 */
