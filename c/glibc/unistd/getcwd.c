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
char * getcwd (char *buffer, size t size) [Function]
The getcwd function returns an absolute fle name representing the current working
directory, storing it in the character array buﬀer that you provide. The size argument
is how you tell the system the allocation size of buﬀer.
The GNU library version of this function also permits you to specify a null pointer for
the buﬀer argument. Then getcwd allocates a buﬀer automatically, as with malloc
(see Section 3.2.2 [Unconstrained Allocation], page 33). If the size is greater than
zero, then the buﬀer is that large; otherwise, the buﬀer is as large as necessary to
hold the result.
The return value is buﬀer on success and a null pointer on failure. The following
errno error conditions are defned for this function:
EINVAL The size argument is zero and buﬀer is not a null pointer.
ERANGE The size argument is less than the length of the working directory name.
You need to allocate a bigger array and try again.
EACCES Permission to read or search a component of the fle name was denied.
You could implement the behavior of GNU’s getcwd (NULL, 0) using only the standard
behavior of getcwd:
char *
gnu_getcwd ()
{
    size_t size = 100;
    while (1)
    {
        char *buffer = (char *) xmalloc (size);
        if (getcwd (buffer, size) == buffer)
        return buffer;
        free (buffer);
        if (errno != ERANGE)
        return 0;
        size *= 2;
    }
}
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
        if (getcwd (buffer, size) == buffer)
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