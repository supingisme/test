/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
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


int ftruncate (int fd, oﬀ t length) [Function]
This is like truncate, but it works on a fle descriptor fd for an opened fle instead of
a fle name to identify the object. The fle must be opened for writing to successfully
carry out the operation.
The POSIX standard leaves it implementation defned what happens if the specifed
new length of the fle is bigger than the original size. The ftruncate function might
simply leave the fle alone and do nothing or it can increase the size to the desired
size. In this later case the extended area should be zero-flled. So using ftruncate is
no reliable way to increase the fle size but if it is possible it is probably the fastest
way. The function also operates on POSIX shared memory segments if these are
implemented by the system.
ftruncate is especially useful in combination with mmap. Since the mapped region
must have a fxed size one cannot enlarge the fle by writing something beyond the
last mapped page. Instead one has to enlarge the fle itself and then remap the fle
with the new size. The example below shows how this works.


When the source fle is compiled with _FILE_OFFSET_BITS == 64 the ftruncate func
tion is in fact ftruncate64 and the type off_t has 64 bits which makes it possible
to handle fles up to 263 bytes in length.
The return value is 0 for success, or −1 for an error. The following errors may occur:
EBADF fd does not correspond to an open fle.
EACCES fd is a directory or not open for writing.
EINVAL length is negative.
EFBIG The operation would extend the fle beyond the limits of the operating
system.
EIO A hardware I/O error occurred.
EPERM The fle is "append-only" or "immutable".
EINTR The operation was interrupted by a signal.


int ftruncate64 (int id, oﬀ64 t length) [Function]
This function is similar to the ftruncate function. The diﬀerence is that the length
argument is 64 bits wide even on 32 bits machines which allows the handling of fles
with sizes up to 263 bytes.
When the source fle is compiled with _FILE_OFFSET_BITS == 64 on a 32 bits machine
this function is actually available under the name ftruncate and so transparently
replaces the 32 bits interface.

*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int fd = open(argv [1], O_WRONLY|O_RDONLY);
    int len = atoi(argv[2]);
    
    printf("%s:%d\n", argv [1], len);
    
    printf("%d\n",ftruncate(fd, len));
    
    printf("%s:%d\n", argv [1], len);
    
    return 0;
}
