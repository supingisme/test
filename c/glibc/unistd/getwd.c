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
char * getwd (char *buffer) [Deprecated Function]
This is similar to getcwd, but has no way to specify the size of the buﬀer. The GNU
library provides getwd only for backwards compatibility with BSD.
The buﬀer argument should be a pointer to an array at least PATH_MAX bytes long
(see Section 31.6 [Limits on File System Capacity], page 782). In the GNU system
there is no limit to the size of a fle name, so this is not necessarily enough space to
contain the directory name. That is why this function is deprecated.

getwd.c:24:9: 警告：不建议使用‘getwd’(声明于 /usr/include/unistd.h:525) [-Wdeprecated-declarations]
         if (getwd (buffer) == buffer)
         ^
/tmp/ccu8c2zl.o：在函数‘gnu_getcwd’中：
getwd.c:(.text+0x28): 警告：the `getwd' function is dangerous and should not be used.
$ ./a.out 
/home/RongTao/test/c/libc/unistd

*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

char *
gnu_getcwd ()
{
    size_t size = 100;
    
    while (1)
    {
        char *buffer = (char *) malloc (size);
        if (getwd (buffer) == buffer)
            return buffer;
        free (buffer);
        if (errno != ERANGE)
            return 0;
        size *= 2;
    }
}

int main()
{
    printf("%s\n",gnu_getcwd ());
    
    return 0;
}