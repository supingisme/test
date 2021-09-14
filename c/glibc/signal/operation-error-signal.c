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

int SIGPIPE [Macro]
Broken pipe. If you use pipes or FIFOs, you have to design your application so that
one process opens the pipe for reading before another starts writing. If the reading
process never starts, or terminates unexpectedly, writing to the pipe or FIFO raises
a SIGPIPE signal. If SIGPIPE is blocked, handled or ignored, the oﬀending call fails
with EPIPE instead.
Pipes and FIFO special fles are discussed in more detail in Chapter 15 [Pipes and
FIFOs], page 384.
Another cause of SIGPIPE is when you try to output to a socket that isn’t connected.
See Section 16.9.5.1 [Sending Data], page 417.
int SIGLOST [Macro]
Resource lost. This signal is generated when you have an advisory lock on an NFS
fle, and the NFS server reboots and forgets about your lock.
In the GNU system, SIGLOST is generated when any server program dies unexpectedly.
It is usually fne to ignore the signal; whatever call was made to the server that died
just returns an error.
int SIGXCPU [Macro]
CPU time limit exceeded. This signal is generated when the process exceeds its soft
resource limit on CPU time. See Section 22.2 [Limiting Resource Usage], page 575.
int SIGXFSZ [Macro]
File size limit exceeded. This signal is generated when the process attempts to extend
a fle so it exceeds the process’s soft resource limit on fle size. See Section 22.2
[Limiting Resource Usage], page 575.




 */

#include <signal.h>
#include <stdio.h>

int main()
{
	printf("SIGPIPE = %d\n", SIGPIPE);
	//printf("SIGLOST = %d\n", SIGLOST);
	printf("SIGXCPU = %d\n", SIGXCPU);
	printf("SIGXFSZ = %d\n", SIGXFSZ);

	return 0;
}
