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
 *	struct passwd * getpwuid (uid t uid) [Function]
 *	This function returns a pointer to a statically-allocated structure containing infor
 *	mation about the user whose user ID is uid. This structure may be overwritten on
 *	subsequent calls to getpwuid.
 *	A null pointer value indicates there is no user in the data base with user ID uid.
 *	int getpwuid_r (uid t uid, struct passwd *result_buf, char *buffer, [Function]
 *	size t buflen, struct passwd **result)
 *	This function is similar to getpwuid in that it returns information about the user
 *	whose user ID is uid. However, it flls the user supplied structure pointed to by
 *	result buf with the information instead of using a static buﬀer. The frst buﬂen
 *	bytes of the additional buﬀer pointed to by buﬀer are used to contain additional
 *	information, normally strings which are pointed to by the elements of the result
 *	structure.
 *	If a user with ID uid is found, the pointer returned in result points to the record
 *	which contains the wanted data (i.e., result contains the value result buf ). If no user
 *	is found or if an error occurred, the pointer returned in result is a null pointer. The
 *	function returns zero or an error code. If the buﬀer buﬀer is too small to contain all
 *	the needed information, the error code ERANGE is returned and errno is set to ERANGE.
 */

#include <stdio.h>
#include <pwd.h>

int main()
{
	struct passwd *_passwd = getpwuid(getuid());

	printf("pw_name = %s\n", _passwd->pw_name);
	printf("pw_passwd = %s\n", _passwd->pw_passwd);
	printf("pw_uid = %d\n", _passwd->pw_uid);
	printf(" pw_gid = %d\n", _passwd->pw_gid);
	printf("pw_gecos = %s\n", _passwd->pw_gecos);
	printf("pw_dir = %s\n", _passwd->pw_dir);
	printf("pw_shell = %s\n", _passwd->pw_shell);

	return 0;
}
