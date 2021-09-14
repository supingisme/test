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

struct passwd * getpwnam (const char *name) [Function]
This function returns a pointer to a statically-allocated structure containing informa
tion about the user whose user name is name. This structure may be overwritten on
subsequent calls to getpwnam.
A null pointer return indicates there is no user named name.
int getpwnam_r (const char *name, struct passwd *result_buf, char [Function]
*buffer, size t buflen, struct passwd **result)
This function is similar to getpwnam in that is returns information about the user
whose user name is name. However, like getpwuid_r, it flls the user supplied buﬀers
in result buf and buﬀer with the information instead of using a static buﬀer.
The return values are the same as for getpwuid_r.


 */

#include <stdio.h>
#include <pwd.h>

int main()
{
	struct passwd *p = getpwuid(getuid());

    struct passwd *_passwd = getpwnam(p->pw_name);
    
    
	printf("pw_name = %s\n", _passwd->pw_name);
	printf("pw_passwd = %s\n", _passwd->pw_passwd);
	printf("pw_uid = %d\n", _passwd->pw_uid);
	printf(" pw_gid = %d\n", _passwd->pw_gid);
	printf("pw_gecos = %s\n", _passwd->pw_gecos);
	printf("pw_dir = %s\n", _passwd->pw_dir);
	printf("pw_shell = %s\n", _passwd->pw_shell);

	return 0;
}
