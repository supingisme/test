/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/*

24.2.3 Alarm Signals
These signals are used to indicate the expiration of timers. See Section 21.5 [Setting an
Alarm], page 569, for information about functions that cause these signals to be sent.
The default behavior for these signals is to cause program termination. This default is
rarely useful, but no other default would be useful; most of the ways of using these signals
would require handler functions in any case.
int SIGALRM [Macro]
This signal typically indicates expiration of a timer that measures real or clock time.
It is used by the alarm function, for example.
int SIGVTALRM [Macro]
This signal typically indicates expiration of a timer that measures CPU time used by
the current process. The name is an abbreviation for “virtual time alarm”.
int SIGPROF [Macro]
This signal typically indicates expiration of a timer that measures both CPU time
used by the current process, and CPU time expended on behalf of the process by the
system. Such a timer is used to implement code profling facilities, hence the name
of this signal.



 */

#include <signal.h>
#include <stdio.h>

int main()
{
	printf("SIGALRM = %d\n", SIGALRM);
	printf("SIGVTALRM = %d\n", SIGVTALRM);
	printf("SIGPROF = %d\n", SIGPROF);

	return 0;
}
