/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:31 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*
int ntp_adjtime (struct timex *tptr) [Function]
The ntp_adjtime function sets the structure specifed by tptr to current values.
In addition, ntp_adjtime updates some settings to match what you pass to it in
*tptr. Use the modes element of *tptr to select what settings to update. You can set
offset, freq, maxerror, esterror, status, constant, and tick.
modes = zero means set nothing.
Only the superuser can update settings.
The return value is 0 on success and other values on failure. The following errno
error conditions are defned for this function:
TIME_ERROR
The high accuracy clock model is not properly set up at the moment, thus
the clock must be considered unsynchronized, and the values should be
treated with care. Another reason could be that the specifed new values
are not allowed.
EPERM The process specifed a settings update, but is not superuser.
For more details see RFC1305 (Network Time Protocol, Version 3) and related doc
uments.
Portability note: Early versions of the GNU C library did not have this function but
did have the synonymous adjtimex.

*/

#include <sys/timex.h>
#include <time.h>
#include <stdio.h>

/* struct ntptimeval{
    struct timeval time;
    long int maxerror;
    long int esterror;
}; */

int main()
{
    struct timex t;
    
    
    printf("%d\n", ntp_adjtime(&t));
    
    return 0;
}