/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 10:11:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
14.6 Deleting Files
You can delete a fle with unlink or remove.
Deletion actually deletes a fle name. If this is the fle’s only name, then the fle is deleted
as well. If the fle has other remaining names (see Section 14.4 [Hard Links], page 356), it
remains accessible under those names.
int unlink (const char *filename) [Function]
The unlink function deletes the fle name flename. If this is a fle’s sole name, the
fle itself is also deleted. (Actually, if any process has the fle open when this happens,
deletion is postponed until all processes have closed the fle.)
The function unlink is declared in the header fle ‘unistd.h’.
This function returns 0 on successful completion, and -1 on error. In addition to the
usual fle name errors (see Section 11.2.3 [File Name Errors], page 224), the following
errno error conditions are defned for this function:
EACCES Write permission is denied for the directory from which the fle is to be
removed, or the directory has the sticky bit set and you do not own the
fle.
EBUSY This error indicates that the fle is being used by the system in such a
way that it can’t be unlinked. For example, you might see this error if the
fle name specifes the root directory or a mount point for a fle system.
ENOENT The fle name to be deleted doesn’t exist.
EPERM On some systems unlink cannot be used to delete the name of a directory,
or at least can only be used this way by a privileged user. To avoid such
problems, use rmdir to delete directories. (In the GNU system unlink
can never delete the name of a directory.)
EROFS The directory containing the fle name to be deleted is on a read-only fle
system and can’t be modifed.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        return -1;
    }
    
    remove(argv[1]);
    
    return 0;
}