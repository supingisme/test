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
/*
 *	29.14.1 The Data Structure for a Group
 *	The functions and data structures for accessing the system group database are declared in
 *	the header fle ‘grp.h’.
 *	struct group [Data Type]
 *	The group structure is used to hold information about an entry in the system group
 *	database. It has at least the following members:
 *	char *gr_name
 *	The name of the group.
 *	gid_t gr_gid
 *	The group ID of the group.
 *	char **gr_mem
 *	A vector of pointers to the names of users in the group. Each user name
 *	is a null-terminated string, and the vector itself is terminated by a null
 *	pointer.
 */

#include <grp.h>
struct group {
   char   *gr_name;       /* group name */
   char   *gr_passwd;     /* group password */
   gid_t   gr_gid;        /* group ID */
   char  **gr_mem;        /* group members */
};

//struct group{
//	char *gr_name;
//	gid_t gr_gid;
//	char **gr_mem;
//};
