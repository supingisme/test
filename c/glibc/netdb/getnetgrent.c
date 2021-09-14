/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:17 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:43:21 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/*
int getnetgrent (char **hostp, char **userp, char **domainp) [Function]
This function returns the next unprocessed entry of the currently selected netgroup.
The string pointers, in which addresses are passed in the arguments hostp, userp, and
domainp, will contain after a successful call pointers to appropriate strings. If the
string in the next entry is empty the pointer has the value NULL. The returned string
pointers are only valid if none of the netgroup related functions are called.
The return value is 1 if the next entry was successfully read. A value of 0 means no
further entries exist or internal errors occurred.
int getnetgrent_r (char **hostp, char **userp, char **domainp, [Function]
char *buffer, int buflen)
This function is similar to getnetgrent with only one exception: the strings the three
string pointers hostp, userp, and domainp point to, are placed in the buﬀer of buﬂen
bytes starting at buﬀer. This means the returned values are valid even after other
netgroup related functions are called.
The return value is 1 if the next entry was successfully read and the buﬀer contains
enough room to place the strings in it. 0 is returned in case no more entries are found,
the buﬀer is too small, or internal errors occurred.
This function is a GNU extension. The original implementation in the SunOS libc
does not provide this function.


void endnetgrent (void) [Function]
This function frees all buﬀers which were allocated to process the last selected net
group. As a result all string pointers returned by calls to getnetgrent are invalid
afterwards.


*/

#include <netdb.h>

int setnetgrent (const char *netgroup);
int getnetgrent (char **hostp, char **userp, char **domainp);
void endnetgrent (void);



int main()
{
    
}