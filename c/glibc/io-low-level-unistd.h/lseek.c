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
#include <unistd.h>
#include <string.h>

/*	off_t lseek (int filedes, oﬀ t offset, int whence) [Function]
 *	The lseek function is used to change the fle position of the fle with descriptor fledes.
 *	The whence argument specifes how the oﬀset should be interpreted, in the same way
 *	as for the fseek function, and it must be one of the symbolic constants SEEK_SET,
 *	SEEK_CUR, or SEEK_END.
 *	SEEK_SET Specifes that whence is a count of characters from the beginning of the
 *	fle.
 *	SEEK_CUR Specifes that whence is a count of characters from the current fle posi
 *	tion. This count may be positive or negative.
 *	SEEK_END Specifes that whence is a count of characters from the end of the fle. A
 *	negative count specifes a position within the current extent of the fle;
 *	a positive count specifes a position past the current end. If you set the
 *	position past the current end, and actually write data, you will extend
 *	the fle with zeros up to that position.
 *
 *	The return value from lseek is normally the resulting fle position, measured in bytes
 *	from the beginning of the fle. You can use this feature together with SEEK_CUR to
 *	read the current fle position.
 *	If you want to append to the fle, setting the fle position to the current end of fle
 *	with SEEK_END is not sufcient. Another process may write more data after you seek
 *	but before you write, extending the fle so the position you write onto clobbers their
 *	data. Instead, use the O_APPEND operating mode; see Section 13.14.3 [I/O Operating
 *	Modes], page 336.
 *	You can set the fle position past the current end of the fle. This does not by itself
 *	make the fle longer; lseek never changes the fle. But subsequent output at that
 *	position will extend the fle. Characters between the previous end of fle and the new
 *	position are flled with zeros. Extending the fle in this way can create a “hole”: the
 *	blocks of zeros are not actually allocated on disk, so the fle takes up less space than
 *	it appears to; it is then called a “sparse fle”.
 *	If the fle position cannot be changed, or the operation is in some way invalid, lseek
 *	returns a value of −1. The following errno error conditions are defned for this
 *	function:
 *	EBADF The fledes is not a valid fle descriptor.
 *	EINVAL The whence argument value is not valid, or the resulting fle oﬀset is not
 *	valid. A fle oﬀset is invalid.
 *	ESPIPE The fledes corresponds to an object that cannot be positioned, such as
 *	a pipe, FIFO or terminal device. (POSIX.1 specifes this error only for
 *	pipes and FIFOs, but in the GNU system, you always get ESPIPE if the
 *	object is not seekable.)
 *
 *	When the source fle is compiled with _FILE_OFFSET_BITS == 64 the lseek function
 *	is in fact lseek64 and the type off_t has 64 bits which makes it possible to handle
 *	fles up to 263 bytes in length.
 *	This function is a cancellation point in multi-threaded programs. This is a problem
 *	if the thread allocates some resources (like memory, fle descriptors, semaphores or
 *	whatever) at the time lseek is called. If the thread gets canceled these resources stay
 *	allocated until the program ends. To avoid this calls to lseek should be protected
 *	using cancellation handlers.
 *	The lseek function is the underlying primitive for the fseek, fseeko, ftell, ftello
 *	and rewind functions, which operate on streams instead of fle descriptors.
 *	off64_t lseek64 (int filedes, oﬀ64 t offset, int whence) [Function]
 *	This function is similar to the lseek function. The diﬀerence is that the oﬀset param
 *	eter is of type off64_t instead of off_t which makes it possible on 32 bit machines
 *	to address fles larger than 231 bytes and up to 263 bytes. The fle descriptor filedes
 *	must be opened using open64 since otherwise the large oﬀsets possible with off64_t
 *	will lead to errors with a descriptor in small fle mode.
 *	When the source fle is compiled with _FILE_OFFSET_BITS == 64 on a 32 bits machine
 *	this function is actually available under the name lseek and so transparently replaces
 *	the 32 bit interface.
 *
 *
 *
 */

int main(int argc, char *argv[])
{
	int d1, d2;
	char buf[4];
	d1 = open ("foo", O_RDONLY);
	d2 = open ("foo", O_RDONLY);
	lseek (d1, 1024, SEEK_SET);
	read (d2, buf, 4);

	return 0;
}
