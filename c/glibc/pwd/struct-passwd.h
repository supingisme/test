/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:21 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/*
 *	struct passwd [Data Type]
 *	The passwd data structure is used to hold information about entries in the system
 *	user data base. It has at least the following members:
 *	char *pw_name
 *	The user’s login name.
 *	char *pw_passwd.
 *	The encrypted password string.
 *	uid_t pw_uid
 *	The user ID number.
 *	gid_t pw_gid
 *	The user’s default group ID number.
 *	char *pw_gecos
 *	A string typically containing the user’s real name, and possibly other
 *	information such as a phone number.
 *	char *pw_dir
 *	The user’s home directory, or initial working directory. This might be a
 *	null pointer, in which case the interpretation is system-dependent.
 *	char *pw_shell
 *	The user’s default shell, or the initial program run when the user logs in.
 *	This might be a null pointer, indicating that the system default should
 *	be used.
 */

#include <pwd.h>

struct passwd {
   char   *pw_name;       /* username */
   char   *pw_passwd;     /* user password */
   uid_t   pw_uid;        /* user ID */
   gid_t   pw_gid;        /* group ID */
   char   *pw_gecos;      /* user information */
   char   *pw_dir;        /* home directory */
   char   *pw_shell;      /* shell program */
};

//struct passwd{
//	char *pw_name;
//	char *pw_passwd;
//	uid_t pw_uid;
//	gid_t pw_gid;
//	char *pw_gecos;
//	char *pw_dir;
//	char *pw_shell;
//};
