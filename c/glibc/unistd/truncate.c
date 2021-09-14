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
14.9.10 File Size
Normally fle sizes are maintained automatically. A fle begins with a size of 0 and is
automatically extended when data is written past its end. It is also possible to empty a fle
completely by an open or fopen call.
However, sometimes it is necessary to reduce the size of a fle. This can be done with
the truncate and ftruncate functions. They were introduced in BSD Unix. ftruncate
was later added to POSIX.1.
Some systems allow you to extend a fle (creating holes) with these functions. This is
useful when using memory-mapped I/O (see Section 13.7 [Memory-mapped I/O], page 309),
where fles are not automatically extended. However, it is not portable but must be imple
mented if mmap allows mapping of fles (i.e., _POSIX_MAPPED_FILES is defned).
Using these functions on anything other than a regular fle gives undefned results. On
many systems, such a call will appear to succeed, without actually accomplishing anything.
int truncate (const char *filename, oﬀ t length) [Function]
The truncate function changes the size of flename to length. If length is shorter
than the previous length, data at the end will be lost. The fle must be writable by
the user to perform this operation.
If length is longer, holes will be added to the end. However, some systems do not
support this feature and will leave the fle unchanged.
When the source fle is compiled with _FILE_OFFSET_BITS == 64 the truncate func
tion is in fact truncate64 and the type off_t has 64 bits which makes it possible to
handle fles up to 263 bytes in length.
The return value is 0 for success, or −1 for an error. In addition to the usual fle
name errors, the following errors may occur:
EACCES The fle is a directory or not writable.
EINVAL length is negative.
EFBIG The operation would extend the fle beyond the limits of the operating
system.
EIO A hardware I/O error occurred.
EPERM The fle is "append-only" or "immutable".
EINTR The operation was interrupted by a signal.
int truncate64 (const char *name, oﬀ64 t length) [Function]
This function is similar to the truncate function. The diﬀerence is that the length
argument is 64 bits wide even on 32 bits machines, which allows the handling of fles
with sizes up to 263 bytes.
When the source fle is compiled with _FILE_OFFSET_BITS == 64 on a 32 bits machine
this function is actually available under the name truncate and so transparently
replaces the 32 bits interface.
*/
#include <stdio.h>
#include <unistd.h>

/*
-rw-rw-r--. 1 RongTao RongTao   51 11月 14 01:44 tmp.out
$ ./a.out tmp.out 30


-rw-rw-r--. 1 RongTao RongTao   30 11月 14 01:44 tmp.out


$ more tmp.out 
rongasdfasdfadsfasdddddddddddd
[RongTao@localhost unistd]$ ./a.out tmp.out 12
tmp.out:12
0
tmp.out:12
[RongTao@localhost unistd]$ more tmp.out 
rongasdfasdf

*/

/*
 *	截断一个文件，如果文件大小大于规定大小，截断
 */
//[root@localhost unistd]# echo "1234567890" > truncate.test
//[root@localhost unistd]# more truncate.test 
//1234567890
//[root@localhost unistd]# ./a.out truncate.test 4
//truncate.test:4
//0
//truncate.test:4
//[root@localhost unistd]# more truncate.test 
//1234
//[root@localhost unistd]# 

int main(int argc, char *argv[])
{
    char *p = argv [1];
    int len = atoi(argv[2]);
    
    printf("%s:%d\n", p, len);
    
    printf("%d\n",truncate(p, len));
    
    printf("%s:%d\n", p, len);
    
    return 0;
}
