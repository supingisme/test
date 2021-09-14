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

struct passwd * fgetpwent (FILE *stream) [Function]
This function reads the next user entry from stream and returns a pointer to the
entry. The structure is statically allocated and is rewritten on subsequent calls to
fgetpwent. You must copy the contents of the structure if you wish to save the
information.
The stream must correspond to a fle in the same format as the standard password
database fle.


int fgetpwent_r (FILE *stream, struct passwd *result_buf, char [Function]
*buffer, size t buflen, struct passwd **result)
This function is similar to fgetpwent in that it reads the next user entry from stream.
But the result is returned in the structure pointed to by result buf. The frst buﬂen
bytes of the additional buﬀer pointed to by buﬀer are used to contain additional
information, normally strings which are pointed to by the elements of the result
structure.
The stream must correspond to a fle in the same format as the standard password
database fle.
If the function returns zero result points to the structure with the wanted data (nor
mally this is in result buf ). If errors occurred the return value is nonzero and result
contains a null pointer.
The way to scan all the entries in the user database is with setpwent, getpwent, and
endpwent.

 */

#include <stdio.h>
#include <pwd.h>

int main()
{
    FILE *fp = fopen("./passwd", "r");
    
	struct passwd *passwd;

    while((passwd = fgetpwent(fp)) != NULL)
    {
        printf("pw_name = %s\n", passwd->pw_name);
        printf("pw_passwd = %s\n", passwd->pw_passwd);
        printf("pw_uid = %d\n", passwd->pw_uid);
        printf(" pw_gid = %d\n", passwd-> pw_gid);
        printf("pw_gecos = %s\n", passwd->pw_gecos);
        printf("pw_dir = %s\n", passwd->pw_dir);
        printf("pw_shell = %s\n", passwd->pw_shell);
        passwd = NULL;
    }
	return 0;
}
