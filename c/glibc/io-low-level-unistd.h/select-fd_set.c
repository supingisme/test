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
/*	fd_set [Data Type]
 *	The fd_set data type represents fle descriptor sets for the select function. It is
 *	actually a bit array.
 *	int FD_SETSIZE [Macro]
 *	The value of this macro is the maximum number of fle descriptors that a fd_set
 *	object can hold information about. On systems with a fxed maximum number, FD_
 *	SETSIZE is at least that number. On some systems, including GNU, there is no
 *	absolute limit on the number of descriptors open, but this macro still has a constant
 *	value which controls the number of bits in an fd_set; if you get a fle descriptor with
 *	a value as high as FD_SETSIZE, you cannot put that descriptor into an fd_set.
 *	void FD_ZERO (fd set *set) [Macro]
 *	This macro initializes the fle descriptor set set to be the empty set.
 *	void FD_SET (int filedes, fd set *set) [Macro]
 *	This macro adds fledes to the fle descriptor set set.
 *	The fledes parameter must not have side eﬀects since it is evaluated more than once.
 *	void FD_CLR (int filedes, fd set *set) [Macro]
 *	This macro removes fledes from the fle descriptor set set.
 *	The fledes parameter must not have side eﬀects since it is evaluated more than once.
 *	int FD_ISSET (int filedes, const fd set *set) [Macro]
 *	This macro returns a nonzero value (true) if fledes is a member of the fle descriptor
 *	set set, and zero (false) otherwise.
 *	The fledes parameter must not have side eﬀects since it is evaluated more than once.
 *
 *
 *	int select (int nfds, fd set *read-fds, fd set *write-fds, fd set [Function]
 *	*except-fds, struct timeval *timeout)
 *	The select function blocks the calling process until there is activity on any of the
 *	specifed sets of fle descriptors, or until the timeout period has expired.
 *	The fle descriptors specifed by the read-fds argument are checked to see if they are
 *	ready for reading; the write-fds fle descriptors are checked to see if they are ready
 *	for writing; and the except-fds fle descriptors are checked for exceptional conditions.
 *	You can pass a null pointer for any of these arguments if you are not interested in
 *	checking for that kind of condition.
 *	A fle descriptor is considered ready for reading if a read call will not block. This
 *	usually includes the read oﬀset being at the end of the fle or there is an error to
 *	report. A server socket is considered ready for reading if there is a pending connec
 *	tion which can be accepted with accept; see Section 16.9.3 [Accepting Connections],
 *	page 415. A client socket is ready for writing when its connection is fully established;
 *	see Section 16.9.1 [Making a Connection], page 413.
 *	“Exceptional conditions” does not mean errors—errors are reported immediately
 *	when an erroneous system call is executed, and do not constitute a state of the
 *	descriptor. Rather, they include conditions such as the presence of an urgent message
 *	on a socket. (See Chapter 16 [Sockets], page 389, for information on urgent messages.)
 *	The select function checks only the frst nfds fle descriptors. The usual thing is to
 *	pass FD_SETSIZE as the value of this argument.
 *	The timeout specifes the maximum time to wait. If you pass a null pointer for this
 *	argument, it means to block indefnitely until one of the fle descriptors is ready.
 *	Otherwise, you should provide the time in struct timeval format; see Section 21.4.2
 *	[High-Resolution Calendar], page 545. Specify zero as the time (a struct timeval
 *	containing all zeros) if you want to fnd out which descriptors are ready without
 *	waiting if none are ready.
 *	The normal return value from select is the total number of ready fle descriptors in
 *	all of the sets. Each of the argument sets is overwritten with information about the
 *	descriptors that are ready for the corresponding operation. Thus, to see if a particular
 *	descriptor desc has input, use FD_ISSET (desc, read-fds) after select returns.
 *	If select returns because the timeout period expires, it returns a value of zero.
 *	Any signal will cause select to return immediately. So if your program uses signals,
 *	you can’t rely on select to keep waiting for the full time specifed. If you want
 *	to be sure of waiting for a particular amount of time, you must check for EINTR and
 *	repeat the select with a newly calculated timeout based on the current time. See the
 *	example below. See also Section 24.5 [Primitives Interrupted by Signals], page 628.
 *	If an error occurs, select returns -1 and does not modify the argument fle descriptor
 *	sets. The following errno error conditions are defned for this function:
 *	EBADF One of the fle descriptor sets specifed an invalid fle descriptor.
 *	EINTR The operation was interrupted by a signal. See Section 24.5 [Primitives
 *	Interrupted by Signals], page 628.
 *	EINVAL The timeout argument is invalid; one of the components is negative or
 *	too large.
 *
 *	Portability Note: The select function is a BSD Unix feature.
 */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
int
input_timeout (int filedes, unsigned int seconds)
{
	fd_set set;
	struct timeval timeout;
	/* Initialize the fle descriptor set. */
	FD_ZERO (&set);
	FD_SET (filedes, &set);
	/* Initialize the timeout data structure. */
	timeout.tv_sec = seconds;
	timeout.tv_usec = 0;
	/* select returns 0 if timeout, 1 if input available, -1 if error. */
	return select (FD_SETSIZE,
				&set, NULL, NULL,
				&timeout);
}
int
main (void)
{
	fprintf (stderr, "select returned %d.\n",
			input_timeout (STDIN_FILENO, 5));
	return 0;
}
