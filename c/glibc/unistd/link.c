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
int link (const char *oldname, const char *newname) [Function]
The link function makes a new link to the existing fle named by oldname, under the
new name newname.
This function returns a value of 0 if it is successful and -1 on failure. In addition
to the usual fle name errors (see Section 11.2.3 [File Name Errors], page 224) for
both oldname and newname, the following errno error conditions are defned for this
function:
EACCES You are not allowed to write to the directory in which the new link is to
be written.
EEXIST There is already a fle named newname. If you want to replace this link
with a new link, you must remove the old link explicitly frst.
EMLINK There are already too many links to the fle named by oldname. (The
maximum number of links to a fle is LINK_MAX; see Section 31.6 [Limits
on File System Capacity], page 782.)
ENOENT The fle named by oldname doesn’t exist. You can’t make a link to a fle
that doesn’t exist.
ENOSPC The directory or fle system that would contain the new link is full and
cannot be extended.
EPERM In the GNU system and some others, you cannot make links to directories.
Many systems allow only privileged users to do so. This error is used to
report the problem.
EROFS The directory containing the new link can’t be modifed because it’s on
a read-only fle system.
EXDEV The directory specifed in newname is on a diﬀerent fle system than the
existing fle.
EIO A hardware error occurred while trying to read or write the to flesystem.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        return -1;
    }
    
    link(argv[1], argv[2]);
    
    return 0;
}