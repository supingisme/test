/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
struct dirent * readdir (DIR *dirstream) [Function]
This function reads the next entry from the directory. It normally returns a pointer to
a structure containing information about the fle. This structure is statically allocated
and can be rewritten by a subsequent call.
Portability Note: On some systems readdir may not return entries for ‘.’ and ‘..’,
even though these are always valid fle names in any directory. See Section 11.2.2
[File Name Resolution], page 224.
If there are no more entries in the directory or an error is detected, readdir returns
a null pointer. The following errno error conditions are defned for this function:
EBADF The dirstream argument is not valid.
readdir is not thread safe. Multiple threads using readdir on the same dirstream
may overwrite the return value. Use readdir_r when this is critical.
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
int
main (void)
{
    DIR *dp;
    struct dirent *ep;
    
    dp = opendir ("./");
    
    if (dp != NULL)
    {
        while (ep = readdir (dp))
            puts (ep->d_name);
        
        (void) closedir (dp);
    }
    else
        perror ("Couldn’t open the directory");

    
    return 0;
}