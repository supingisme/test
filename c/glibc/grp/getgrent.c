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

void setgrent (void) [Function]
This function initializes a stream for reading from the group data base. You use this
stream by calling getgrent or getgrent_r.


struct group * getgrent (void) [Function]
The getgrent function reads the next entry from the stream initialized by setgrent.
It returns a pointer to the entry. The structure is statically allocated and is overwrit
ten on subsequent calls to getgrent. You must copy the contents of the structure if
you wish to save the information.
int getgrent_r (struct group *result_buf, char *buffer, size t [Function]
buflen, struct group **result)
This function is similar to getgrent in that it returns the next entry from the stream
initialized by setgrent. Like fgetgrent_r, it places the result in user-supplied
buﬀers pointed to result buf and buﬀer.
If the function returns zero result contains a pointer to the data (normally equal to
result buf ). If errors occurred the return value is non-zero and result contains a null
pointer.


void endgrent (void) [Function]
This function closes the internal stream used by getgrent or getgrent_r.

*/
#include <stdio.h>
#include <grp.h>

int main()
{
    setgrent();
    
    struct group *group = getgrent();
    
    printf("%s:%d:%s\n", group->gr_name, group->gr_gid, group->gr_mem[0]);
    
    endgrent();
    
    return 0;
}   