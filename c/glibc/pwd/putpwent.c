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

int putpwent (const struct passwd *p, FILE *stream) [Function
This function writes the user entry *p to the stream stream, in the format used fo
the standard user database fle. The return value is zero on success and nonzero on
failure.
This function exists for compatibility with SVID. We recommend that you avoid using
it, because it makes sense only on the assumption that the struct passwd structur
has no members except the standard ones; on a system which merges the traditiona
Unix data base with other extended information about users, adding an entry using
this function would inevitably leave out much of the important information.

The group and user ID felds are left empty if the group or user name starts with a -
or +.
The function putpwent is declared in ‘pwd.h’.

 */

#include <stdio.h>
#include <pwd.h>

int main()
{
    setpwent();
    
    FILE *fp = fopen("./new_passwd", "w");
    
    struct passwd *passwd;

    while((passwd = getpwent()) != NULL)
    {
        printf("%s:%s:%d:%d:%s%s%s\n", 
                passwd->pw_name, passwd->pw_passwd, passwd->pw_uid, 
                passwd-> pw_gid, passwd->pw_gecos, passwd->pw_dir, passwd->pw_shell);
        putpwent(passwd, fp);
        passwd = NULL;
    }
    
    endpwent();
    close(fp);
	return 0;
}
