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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*	int open (const char *filename, int flags[, mode t mode]) [Function]
 *	The open function creates and returns a new fle descriptor for the fle named by
 *	flename. Initially, the fle position indicator for the fle is at the beginning of the fle.
 *	The argument mode is used only when a fle is created, but it doesn’t hurt to supply
 *	the argument in any case.
 *	The ﬂags argument controls how the fle is to be opened. This is a bit mask; you create
 *	the value by the bitwise OR of the appropriate parameters (using the ‘|’ operator in
 *	C). See Section 13.14 [File Status Flags], page 333, for the parameters available.
 *	The normal return value from open is a non-negative integer fle descriptor. In the
 *	case of an error, a value of −1 is returned instead. In addition to the usual fle name
 *	errors (see Section 11.2.3 [File Name Errors], page 224), the following errno error
 *	conditions are defned for this function:
 *	EACCES The fle exists but is not readable/writable as requested by the ﬂags
 *	argument, the fle does not exist and the directory is unwritable so it
 *	cannot be created.
 *	EEXIST Both O_CREAT and O_EXCL are set, and the named fle already exists.
 *	EINTR The open operation was interrupted by a signal. See Section 24.5 [Prim
 *	itives Interrupted by Signals], page 628.
 *	EISDIR The ﬂags argument specifed write access, and the fle is a directory.
 *	EMFILE The process has too many fles open. The maximum number of fle
 *	descriptors is controlled by the RLIMIT_NOFILE resource limit; see
 *	Section 22.2 [Limiting Resource Usage], page 575.
 *
 *	ENFILE The entire system, or perhaps the fle system which contains the directory,
 *	cannot support any additional open fles at the moment. (This problem
 *	cannot happen on the GNU system.)
 *	ENOENT The named fle does not exist, and O_CREAT is not specifed.
 *	ENOSPC The directory or fle system that would contain the new fle cannot be
 *	extended, because there is no disk space left.
 *	ENXIO O_NONBLOCK and O_WRONLY are both set in the ﬂags argument, the
 *	fle named by flename is a FIFO (see Chapter 15 [Pipes and FIFOs],
 *	page 384), and no process has the fle open for reading.
 *	EROFS The fle resides on a read-only fle system and any of O_WRONLY, O_RDWR,
 *	and O_TRUNC are set in the ﬂags argument, or O_CREAT is set and the fle
 *	does not already exist.
 *	If on a 32 bit machine the sources are translated with _FILE_OFFSET_BITS == 64 the
 *	function open returns a fle descriptor opened in the large fle mode which enables
 *	the fle handling functions to use fles up to 263 bytes in size and oﬀset from −263
 *	to 263. This happens transparently for the user since all of the lowlevel fle handling
 *	functions are equally replaced.
 *	This function is a cancellation point in multi-threaded programs. This is a problem
 *	if the thread allocates some resources (like memory, fle descriptors, semaphores or
 *	whatever) at the time open is called. If the thread gets canceled these resources stay
 *	allocated until the program ends. To avoid this calls to open should be protected
 *	using cancellation handlers.
 *	The open function is the underlying primitive for the fopen and freopen functions,
 *	that create streams.
 *	int open64 (const char *filename, int flags[, mode t mode]) [Function]
 *	This function is similar to open. It returns a fle descriptor which can be used to
 *	access the fle named by flename. The only diﬀerence is that on 32 bit systems the
 *	fle is opened in the large fle mode. I.e., fle length and fle oﬀsets can exceed 31 bits.
 *	When the sources are translated with _FILE_OFFSET_BITS == 64 this function is ac
 *	tually available under the name open. I.e., the new, extended API using 64 bit fle
 *	sizes and oﬀsets transparently replaces the old API.
 *	int creat (const char *filename, mode t mode) [Obsolete function]
 *	This function is obsolete. The call:
 *	creat (filename, mode)
 *	is equivalent to:
 *	open (filename, O_WRONLY | O_CREAT | O_TRUNC, mode)
 *	If on a 32 bit machine the sources are translated with _FILE_OFFSET_BITS == 64 the
 *	function creat returns a fle descriptor opened in the large fle mode which enables
 *	the fle handling functions to use fles up to 263 in size and oﬀset from −263 to 263.
 *	This happens transparently for the user since all of the lowlevel fle handling functions
 *	are equally replaced.
 *
 *
 *	int creat64 (const char *filename, mode t mode) [Obsolete function]
 *	This function is similar to creat. It returns a fle descriptor which can be used to
 *	access the fle named by flename. The only the diﬀerence is that on 32 bit systems
 *	the fle is opened in the large fle mode. I.e., fle length and fle oﬀsets can exceed 31
 *	bits.
*	To use this fle descriptor one must not use the normal operations but instead the
*	counterparts named *64, e.g., read64.
*	When the sources are translated with _FILE_OFFSET_BITS == 64 this function is ac
*	tually available under the name open. I.e., the new, extended API using 64 bit fle
*	sizes and oﬀsets transparently replaces the old API.
*	int close (int filedes) [Function]
*	The function close closes the fle descriptor fledes. Closing a fle has the following
*	consequences:
*	• The fle descriptor is deallocated.
*	• Any record locks owned by the process on the fle are unlocked.
*	• When all fle descriptors associated with a pipe or FIFO have been closed, any
*	unread data is discarded.
 */

int main(int argc, char *argv[])
{

	int fp = open(argv[1],  EEXIST);

	printf("file:%s, fp:%d\n", argv[1], fp);
	//write(fp, "RongTao\n", 12);

	close(fp);

	return 0;
}
