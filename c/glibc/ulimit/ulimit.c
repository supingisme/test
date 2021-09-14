/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*

int ulimit (int cmd, ...) [Function]
ulimit gets the current limit or sets the current and maximum limit for a particular
resource for the calling process according to the command cmd.a
If you are getting a limit, the command argument is the only argument. If you are
setting a limit, there is a second argument: long int limit which is the value to which
you are setting the limit.
The cmd values and the operations they specify are:
GETFSIZE Get the current limit on the size of a fle, in units of 512 bytes.
SETFSIZE Set the current and maximum limit on the size of a fle to limit * 512
bytes.
There are also some other cmd values that may do things on some systems, but they
are not supported.
Only the superuser may increase a maximum limit.
When you successfully get a limit, the return value of ulimit is that limit, which is
never negative. When you successfully set a limit, the return value is zero. When the
function fails, the return value is -1 and errno is set according to the reason:
EPERM A process tried to increase a maximum limit, but is not superuser.

*/

/* Constants used as the first parameter for `ulimit'.  They denote limits
 * extern long int ulimit (int __cmd, ...) __THROW;
 * #endif 
 * ulimit.h */


// GETFSIZE 
// SETFSIZE 
// int ulimit (int cmd, ...);


#include <ulimit.h>
#include <stdio.h>
#include <sys/vlimit.h>

int main()
{
    
    //printf("%d:%d\n", GETFSIZE, ulimit(GETFSIZE));
    
    
	return 0;
}
