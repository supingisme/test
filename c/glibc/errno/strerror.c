/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
	printf("%d\n", errno);

	if(1)
	{
		perror("RongTao\n");
		//exit(1);

	}

	printf("%d:%s\n", errno, strerror(errno));
	printf("%d:%s\n", EPERM, strerror(EPERM));
	printf("%d:%s\n", ENOENT, strerror(ENOENT));
	printf("%d:%s\n", ESRCH, strerror(ESRCH));
	printf("%d:%s\n", EINTR, strerror(EINTR));
	printf("%d:%s\n", EIO, strerror(EIO));
	printf("%d:%s\n", ENXIO, strerror(ENXIO));
	printf("%d:%s\n", E2BIG, strerror(E2BIG));
	printf("%d:%s\n", ENOEXEC, strerror(ENOEXEC));
	printf("%d:%s\n", EBADF, strerror(EBADF));
	printf("%d:%s\n", ECHILD, strerror(ECHILD));
	printf("%d:%s\n", EDEADLK, strerror(EDEADLK));
    
	printf("%d:%s\n", EAGAIN, strerror(EAGAIN));
    
    
	return 0;
}

/*
int EPERM [Macro]
Operation not permitted; only the owner of the fle (or other resource) or processes
with special privileges can perform the operation.
int ENOENT [Macro]
No such fle or directory. This is a “fle doesn’t exist” error for ordinary fles that are
referenced in contexts where they are expected to already exist.
int ESRCH [Macro]
No process matches the specifed process ID.
int EINTR [Macro]
Interrupted function call; an asynchronous signal occurred and prevented completion
of the call. When this happens, you should try the call again.
You can choose to have functions resume after a signal that is handled, rather than
failing with EINTR; see Section 24.5 [Primitives Interrupted by Signals], page 628.
int EIO [Macro]
Input/output error; usually used for physical read or write errors.
int ENXIO [Macro]
No such device or address. The system tried to use the device represented by a fle
you specifed, and it couldn’t fnd the device. This can mean that the device fle was
installed incorrectly, or that the physical device is missing or not correctly attached
to the computer.
int E2BIG [Macro]
Argument list too long; used when the arguments passed to a new program being
executed with one of the exec functions (see Section 26.5 [Executing a File], page 691)
occupy too much memory space. This condition never arises in the GNU system.
int ENOEXEC [Macro]
Invalid executable fle format. This condition is detected by the exec functions; see
Section 26.5 [Executing a File], page 691.
int EBADF [Macro]
Bad fle descriptor; for example, I/O on a descriptor that has been closed or reading
from a descriptor open only for writing (or vice versa).
int ECHILD [Macro]
There are no child processes. This error happens on operations that are supposed to
manipulate child processes, when there aren’t any processes to manipulate.
int EDEADLK [Macro]
Deadlock avoided; allocating a system resource would have resulted in a deadlock
situation. The system does not guarantee that it will notice all such situations.
This error means you got lucky and the system noticed; it might just hang. See
Section 13.15 [File Locks], page 338, for an example.
int ENOMEM [Macro]
No memory available. The system cannot allocate more virtual memory because its
capacity is full.
int EACCES [Macro]
Permission denied; the fle permissions do not allow the attempted operation.
int EFAULT [Macro]
Bad address; an invalid pointer was detected. In the GNU system, this error never
happens; you get a signal instead.
int ENOTBLK [Macro]
A fle that isn’t a block special fle was given in a situation that requires one. For
example, trying to mount an ordinary fle as a fle system in Unix gives this error.
int EBUSY [Macro]
Resource busy; a system resource that can’t be shared is already in use. For example,
if you try to delete a fle that is the root of a currently mounted flesystem, you get
this error.
int EEXIST [Macro]
File exists; an existing fle was specifed in a context where it only makes sense to
specify a new fle.
int EXDEV [Macro]
An attempt to make an improper link across fle systems was detected. This happens
not only when you use link (see Section 14.4 [Hard Links], page 356) but also when
you rename a fle with rename (see Section 14.7 [Renaming Files], page 360).
int ENODEV [Macro]
The wrong type of device was given to a function that expects a particular sort of
device.
int ENOTDIR [Macro]
A fle that isn’t a directory was specifed when a directory is required.
int EISDIR [Macro]
File is a directory; you cannot open a directory for writing, or create or remove hard
links to it.
int EINVAL [Macro]
Invalid argument. This is used to indicate various kinds of problems with passing the
wrong argument to a library function.
int EMFILE [Macro]
The current process has too many fles open and can’t open any more. Duplicate
descriptors do count toward this limit.
In BSD and GNU, the number of open fles is controlled by a resource limit that
can usually be increased. If you get this error, you might want to increase the
RLIMIT_NOFILE limit or make it unlimited; see Section 22.2 [Limiting Resource Us
age], page 575.
int ENFILE [Macro]
There are too many distinct fle openings in the entire system. Note that any number
of linked channels count as just one fle opening; see Section 13.5.1 [Linked Channels],
page 307. This error never occurs in the GNU system.
int ENOTTY [Macro]
Inappropriate I/O control operation, such as trying to set terminal modes on an
ordinary fle.
int ETXTBSY [Macro]
An attempt to execute a fle that is currently open for writing, or write to a fle that
is currently being executed. Often using a debugger to run a program is considered
having it open for writing and will cause this error. (The name stands for “text fle
busy”.) This is not an error in the GNU system; the text is copied as necessary.
int EFBIG [Macro]
File too big; the size of a fle would be larger than allowed by the system.
int ENOSPC [Macro]
No space left on device; write operation on a fle failed because the disk is full.
int ESPIPE [Macro]
Invalid seek operation (such as on a pipe).
int EROFS [Macro]
An attempt was made to modify something on a read-only fle system.
int EMLINK [Macro]
Too many links; the link count of a single fle would become too large. rename can
cause this error if the fle being renamed already has as many links as it can take (see
Section 14.7 [Renaming Files], page 360).
int EPIPE [Macro]
Broken pipe; there is no process reading from the other end of a pipe. Every library
function that returns this error code also generates a SIGPIPE signal; this signal
terminates the program if not handled or blocked. Thus, your program will never
actually see EPIPE unless it has handled or blocked SIGPIPE.
int EDOM [Macro]
Domain error; used by mathematical functions when an argument value does not fall
into the domain over which the function is defned.
int ERANGE [Macro]
Range error; used by mathematical functions when the result value is not repre
sentable because of overﬂow or underﬂow.
int EAGAIN [Macro]
Resource temporarily unavailable; the call might work if you try again later. The
macro EWOULDBLOCK is another name for EAGAIN; they are always the same in the
GNU C library.
This error can happen in a few diﬀerent situations:
• An operation that would block was attempted on an object that has non-blocking
mode selected. Trying the same operation again will block until some exter
nal condition makes it possible to read, write, or connect (whatever the opera
tion). You can use select to fnd out when the operation will be possible; see
Section 13.8 [Waiting for Input or Output], page 313.
Portability Note: In many older Unix systems, this condition was indicated by
EWOULDBLOCK, which was a distinct error code diﬀerent from EAGAIN. To make
your program portable, you should check for both codes and treat them the same.
• A temporary resource shortage made an operation impossible. fork can return
this error. It indicates that the shortage is expected to pass, so your program
can try the call again later and it may succeed. It is probably a good idea to
delay for a few seconds before trying it again, to allow time for other processes
to release scarce resources. Such shortages are usually fairly serious and aﬀect
the whole system, so usually an interactive program should report the error to
the user and return to its command loop.
int EWOULDBLOCK [Macro]
In the GNU C library, this is another name for EAGAIN (above). The values are always
the same, on every operating system.
C libraries in many older Unix systems have EWOULDBLOCK as a separate error code.
int EINPROGRESS [Macro]
An operation that cannot complete immediately was initiated on an object that has
non-blocking mode selected. Some functions that must always block (such as connect;

*/