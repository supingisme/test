/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
14.5 Symbolic Links
The GNU system supports soft links or symbolic links. This is a kind of “fle” that is
essentially a pointer to another fle name. Unlike hard links, symbolic links can be made
to directories or across fle systems with no restrictions. You can also make a symbolic link
to a name which is not the name of any fle. (Opening this link will fail until a fle by
that name is created.) Likewise, if the symbolic link points to an existing fle which is later
deleted, the symbolic link continues to point to the same fle name even though the name
no longer names any fle.
The reason symbolic links work the way they do is that special things happen when you
try to open the link. The open function realizes you have specifed the name of a link, reads
the fle name contained in the link, and opens that fle name instead. The stat function
likewise operates on the fle that the symbolic link points to, instead of on the link itself.
By contrast, other operations such as deleting or renaming the fle operate on the link
itself. The functions readlink and lstat also refrain from following symbolic links, because
their purpose is to obtain information about the link. link, the function that makes a hard
link, does too. It makes a hard link to the symbolic link, which one rarely wants.
Some systems have for some functions operating on fles have a limit on how many
symbolic links are followed when resolving a path name. The limit if it exists is published
in the ‘sys/param.h’ header fle.
int MAXSYMLINKS [Macro]
The macro MAXSYMLINKS specifes how many symlinks some function will follow before
returning ELOOP. Not all functions behave the same and this value is not the same a
that returned for _SC_SYMLOOP by sysconf. In fact, the sysconf result can indicate
that there is no fxed limit although MAXSYMLINKS exists and has a fnite value.
Prototypes for most of the functions listed in this section are in ‘unistd.h’.
int symlink (const char *oldname, const char *newname) [Function]
The symlink function makes a symbolic link to oldname named newname.
The normal return value from symlink is 0. A return value of -1 indicates an error.
In addition to the usual fle name syntax errors (see Section 11.2.3 [File Name Errors],
page 224), the following errno error conditions are defned for this function:
EEXIST There is already an existing fle named newname.
EROFS The fle newname would exist on a read-only fle system.
ENOSPC The directory or fle system cannot be extended to make the new link.
EIO A hardware error occurred while reading or writing data on the disk.



*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/param.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        return -1;
    }
    
    symlink(argv[1], argv[2]);
    
    return 0;
}