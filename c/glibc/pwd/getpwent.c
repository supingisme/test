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
void setpwent (void) [Function]
This function initializes a stream which getpwent and getpwent_r use to read the
user database.



struct passwd * getpwent (void) [Function]
The getpwent function reads the next entry from the stream initialized by setpwent.
It returns a pointer to the entry. The structure is statically allocated and is rewritten
on subsequent calls to getpwent. You must copy the contents of the structure if you
wish to save the information.
A null pointer is returned when no more entries are available.
int getpwent_r (struct passwd *result_buf, char *buffer, int [Function]
buflen, struct passwd **result)
This function is similar to getpwent in that it returns the next entry from the stream
initialized by setpwent. Like fgetpwent_r, it uses the user-supplied buﬀers in re
sult buf and buﬀer to return the information requested.
The return values are the same as for fgetpwent_r.



void endpwent (void) [Function]
This function closes the internal stream used by getpwent or getpwent_r.

 */

#include <stdio.h>
#include <pwd.h>

int main()
{
    setpwent();
    
    
    struct passwd *_passwd;

    while((_passwd = getpwent()) != NULL)
    {
        printf("%s:%s:%d:%d:%s:%s:%s\n", 
                _passwd->pw_name, _passwd->pw_passwd, _passwd->pw_uid, 
                _passwd->pw_gid, _passwd->pw_gecos, _passwd->pw_dir, _passwd->pw_shell);
        
        _passwd = NULL;
    }
    
    endpwent();
    
	return 0;
}
