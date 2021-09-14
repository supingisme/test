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
/*	13.9 Synchronizing I/O operations
 *	In most modern operating systems, the normal I/O operations are not executed syn
 *	chronously. I.e., even if a write system call returns, this does not mean the data is actually
 *	written to the media, e.g., the disk.
 *	In situations where synchronization points are necessary, you can use special functions
 *	which ensure that all operations fnish before they return.
 *	int sync (void) [Function]
 *	A call to this function will not return as long as there is data which has not been
 *	written to the device. All dirty buﬀers in the kernel will be written and so an overall
 *	consistent system can be achieved (if no other process in parallel writes data).
 *	A prototype for sync can be found in ‘unistd.h’.
 *
 *	The return value is zero to indicate no error.
 *	Programs more often want to ensure that data written to a given fle is committed,
 *	rather than all data in the system. For this, sync is overkill.
 *	int fsync (int fildes) [Function]
 *	The fsync function can be used to make sure all data associated with the open fle
 *	fldes is written to the device associated with the descriptor. The function call does
 *	not return unless all actions have fnished.
 *	A prototype for fsync can be found in ‘unistd.h’.
 *	This function is a cancellation point in multi-threaded programs. This is a problem
 *	if the thread allocates some resources (like memory, fle descriptors, semaphores or
 *	whatever) at the time fsync is called. If the thread gets canceled these resources stay
 *	allocated until the program ends. To avoid this, calls to fsync should be protected
 *	using cancellation handlers.
 *	The return value of the function is zero if no error occurred. Otherwise it is −1 and
 *	the global variable errno is set to the following values:
 *	EBADF The descriptor fldes is not valid.
 *	EINVAL No synchronization is possible since the system does not implement this.
 *	Sometimes it is not even necessary to write all data associated with a fle descriptor. E.g.,
 *	in database fles which do not change in size it is enough to write all the fle content data to
 *	the device. Meta-information, like the modifcation time etc., are not that important and
 *	leaving such information uncommitted does not prevent a successful recovering of the fle
 *	in case of a problem.
 *	int fdatasync (int fildes) [Function]
 *	When a call to the fdatasync function returns, it is ensured that all of the fle data
 *	is written to the device. For all pending I/O operations, the parts guaranteeing data
 *	integrity fnished.
 *	Not all systems implement the fdatasync operation. On systems missing this func
 *	tionality fdatasync is emulated by a call to fsync since the performed actions are a
 *	superset of those required by fdatasync.
 *	The prototype for fdatasync is in ‘unistd.h’.
 *	The return value of the function is zero if no error occurred. Otherwise it is −1 and
 *	the global variable errno is set to the following values:
 *	EBADF The descriptor fldes is not valid.
 *	EINVAL No synchronization is possible since the system does not implement this.
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/*	sync-fsync-fdatasync.c:52:5: 错误：与‘sync’类型冲突
 *	 int sync (void);
 *	      ^
 *	      In file included from sync-fsync-fdatasync.c:50:0:
 *  /usr/include/unistd.h:994:13: 附注：‘sync’的上一个声明在此
 *  extern void sync (void) __THROW;
 */
//int sync (void);
int fsync (int fildes);
int fdatasync (int fildes);

const char * filename = "journal.log";

void write_entry(char *entry)
{
	int fd = open(filename, O_WRONLY|O_CREAT|O_APPEND, 0660);
	write(fd, entry, strlen(entry));
	write(fd, "\n", 1);
	fsync(fd);
	close(fd);
}

int main()
{
	sync();

	fsync(fileno(stdin));

	
	write_entry("Sylincom...");


	return 0;
}
