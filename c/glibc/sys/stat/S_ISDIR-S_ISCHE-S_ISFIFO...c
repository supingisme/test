/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*	14.9.2 Reading the Attributes of a File

14.9.3 Testing the Type of a File
The fle mode, stored in the st_mode feld of the fle attributes, contains two kinds of
information: the fle type code, and the access permission bits. This section discusses only
the type code, which you can use to tell whether the fle is a directory, socket, symbolic
link, and so on. For details about access permissions see Section 14.9.5 [The Mode Bits for
Access Permission], page 370.
There are two ways you can access the fle type information in a fle mode. Firstly,
for each fle type there is a predicate macro which examines a given fle mode and returns
whether it is of that type or not. Secondly, you can mask out the rest of the fle mode to


leave just the fle type code, and compare this against constants for each of the supported
fle types.
All of the symbols listed in this section are defned in the header fle ‘sys/stat.h’.
The following predicate macros test the type of a fle, given the value m which is the
st_mode feld returned by stat on that fle:
int S_ISDIR (mode t m) [Macro]
This macro returns non-zero if the fle is a directory.
int S_ISCHR (mode t m) [Macro]
This macro returns non-zero if the fle is a character special fle (a device like a
terminal).
int S_ISBLK (mode t m) [Macro]
This macro returns non-zero if the fle is a block special fle (a device like a disk).
int S_ISREG (mode t m) [Macro]
This macro returns non-zero if the fle is a regular fle.
int S_ISFIFO (mode t m) [Macro]
This macro returns non-zero if the fle is a FIFO special fle, or a pipe. See Chapter 15
[Pipes and FIFOs], page 384.
int S_ISLNK (mode t m) [Macro]
This macro returns non-zero if the fle is a symbolic link. See Section 14.5 [Symbolic
Links], page 357.
int S_ISSOCK (mode t m) [Macro]
This macro returns non-zero if the fle is a socket. See Chapter 16 [Sockets], page 389.
An alternate non-POSIX method of testing the fle type is supported for compatibility
with BSD. The mode can be bitwise AND-ed with S_IFMT to extract the fle type code, and
compared to the appropriate constant. For example,
S_ISCHR (mode)
is equivalent to:
((mode & S_IFMT) == S_IFCHR)
int S_IFMT [Macro]
This is a bit mask used to extract the fle type code from a mode value.
These are the symbolic names for the diﬀerent fle type codes:
S_IFDIR This is the fle type constant of a directory fle.
S_IFCHR This is the fle type constant of a character-oriented device fle.
S_IFBLK This is the fle type constant of a block-oriented device fle.
S_IFREG This is the fle type constant of a regular fle.
S_IFLNK This is the fle type constant of a symbolic link.
S_IFSOCK This is the fle type constant of a socket.

S_IFIFO This is the fle type constant of a FIFO or pipe.
The POSIX.1b standard introduced a few more objects which possibly can be imple
mented as object in the flesystem. These are message queues, semaphores, and shared
memory objects. To allow diﬀerentiating these objects from other fles the POSIX standard
introduces three new test macros. But unlike the other macros it does not take the value
of the st_mode feld as the parameter. Instead they expect a pointer to the whole struct
stat structure.
int S_TYPEISMQ (struct stat *s) [Macro]
If the system implement POSIX message queues as distinct objects and the fle is
a message queue object, this macro returns a non-zero value. In all other cases the
result is zero.
int S_TYPEISSEM (struct stat *s) [Macro]
If the system implement POSIX semaphores as distinct objects and the fle is a
semaphore object, this macro returns a non-zero value. In all other cases the result
is zero.
int S_TYPEISSHM (struct stat *s) [Macro]
If the system implement POSIX shared memory objects as distinct objects and the
fle is an shared memory object, this macro returns a non-zero value. In all other
cases the result is zero.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat buf;
	stat(argv[1], &buf);	

	printf("mode:%d\n", buf.st_mode);
	printf("ino:%d\n", buf.st_ino);

	printf("type:S_ISDIR:%d\n", S_ISDIR(buf.st_mode));
	printf("type:S_ISCHR:%d\n", S_ISCHR(buf.st_mode));
	printf("type:S_ISBLK:%d\n", S_ISBLK(buf.st_mode));
	printf("type:S_ISREG:%d\n", S_ISREG(buf.st_mode));
	printf("type:S_ISLNK:%d\n", S_ISLNK(buf.st_mode));
	printf("type:S_ISSOCK:%d\n", S_ISSOCK(buf.st_mode));
	printf("type:S_IFMT:%d\n", S_IFMT);
    
	printf("type:S_TYPEISMQ:%d\n", S_TYPEISMQ(&buf));
	printf("type:S_TYPEISSEM:%d\n", S_TYPEISSEM(&buf));
	printf("type:S_TYPEISSHM:%d\n", S_TYPEISSHM(&buf));
    
	return 0;
}
