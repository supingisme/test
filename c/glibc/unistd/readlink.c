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
int readlink (const char *filename, char *buffer, size t size) [Function]
The readlink function gets the value of the symbolic link flename. The fle name that
the link points to is copied into buﬀer. This fle name string is not null-terminated;
readlink normally returns the number of characters copied. The size argument
specifes the maximum number of characters to copy, usually the allocation size of
buﬀer.
If the return value equals size, you cannot tell whether or not there was room to
return the entire name. So make a bigger buﬀer and call readlink again. Here is an
example:
char *
readlink_malloc (const char *filename)
{
int size = 100;
char *buffer = NULL;
while (1)
{
buffer = (char *) xrealloc (buffer, size);
int nchars = readlink (filename, buffer, size);
if (nchars < 0)
{
free (buffer);
return NULL;
}
if (nchars < size)
return buffer;
size *= 2;
}
}
A value of -1 is returned in case of error. In addition to the usual fle name errors (see
Section 11.2.3 [File Name Errors], page 224), the following errno error conditions are
defned for this function:
EINVAL The named fle is not a symbolic link.
EIO A hardware error occurred while reading or writing data on the disk.
In some situations it is desirable to resolve all the symbolic links to get the real name of
a fle where no prefx names a symbolic link which is followed and no flename in the path
is . or ... This is for instance desirable if fles have to be compare in which case diﬀerent
names can refer to the same inode.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/param.h>

char *
readlink_malloc (const char *filename)
{
    int size = 100;
    char *buffer = NULL;
    while (1)
    {
        buffer = (char *) realloc (buffer, size);
        int nchars = readlink (filename, buffer, size);
        
        if (nchars < 0)
        {
            free (buffer);
            return NULL;
        }
        if (nchars < size)
            return buffer;
        
        size *= 2;
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        return -1;
    }
    
    symlink(argv[1], argv[2]);
    
    //printf("%s\n", readlink_malloc(argv[1]));
    printf("%s: %s\n", argv[2], readlink_malloc(argv[2]));
    
    return 0;
}