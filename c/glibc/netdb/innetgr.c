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

int innetgr (const char *netgroup, const char *host, const char [Function]
*user, const char *domain)
This function tests whether the triple specifed by the parameters hostp, userp, and
domainp is part of the netgroup netgroup. Using this function has the advantage that
1. no other netgroup function can use the global netgroup state since internal locking
is used and
2. the function is implemented more efciently than successive calls to the other
set/get/endnetgrent functions.
Any of the pointers hostp, userp, and domainp can be NULL which means any value
is accepted in this position. This is also true for the name - which should not match
any other string otherwise.
The return value is 1 if an entry matching the given triple is found in the netgroup.
The return value is 0 if the netgroup itself is not found, the netgroup does not contain
the triple or internal errors occurred.


*/

#include <netdb.h>

int innetgr (const char *netgroup, const char *host, const char *user, const char *domain);


int main()
{
    
}