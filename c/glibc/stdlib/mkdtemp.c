/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*	char * mkdtemp (char *template) [Function]
 *	The mkdtemp function creates a directory with a unique name. If it succeeds, it
 *	overwrites template with the name of the directory, and returns template. As with
 *	mktemp and mkstemp, template should be a string ending with ‘XXXXXX’.
 *	If mkdtemp cannot create an uniquely named directory, it returns NULL and sets errno
 *	appropriately. If template does not end with ‘XXXXXX’, mkdtemp returns NULL and
 *	does not modify template. errno will be set to EINVAL in this case.
 *	The directory is created using mode 0700.
 *
 */

#include <stdlib.h>

char *mkdtemp(char *template);
