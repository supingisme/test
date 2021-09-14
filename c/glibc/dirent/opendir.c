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
14.2.2 Opening a Directory Stream
This section describes how to open a directory stream. All the symbols are declared in the
header fle ‘dirent.h’.
DIR [Data Type]
The DIR data type represents a directory stream.
You shouldn’t ever allocate objects of the struct dirent or DIR data types, since the
directory access functions do that for you. Instead, you refer to these objects using the
pointers returned by the following functions.
DIR * opendir (const char *dirname) [Function]
The opendir function opens and returns a directory stream for reading the directory
whose fle name is dirname. The stream has type DIR *.
If unsuccessful, opendir returns a null pointer. In addition to the usual fle name
errors (see Section 11.2.3 [File Name Errors], page 224), the following errno error
conditions are defned for this function:
EACCES Read permission is denied for the directory named by dirname.
EMFILE The process has too many fles open.
ENFILE The entire system, or perhaps the fle system which contains the directory,
cannot support any additional open fles at the moment. (This problem
cannot happen on the GNU system.)
ENOMEM Not enough memory available.
The DIR type is typically implemented using a fle descriptor, and the opendir
function in terms of the open function. See Chapter 13 [Low-Level Input/Output],
page 296. Directory streams and the underlying fle descriptors are closed on exec
(see Section 26.5 [Executing a File], page 691).
The directory which is opened for reading by opendir is identifed by the name. In some
situations this is not sufcient. Or the way opendir implicitly creates a fle descriptor for
the directory is not the way a program might want it. In these cases an alternative interface
can be used.
*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR *dir = opendir("/home/RongTao/test");
    struct dirent *diren;
    
    while(diren = readdir(dir))
    {
        printf("%s, %d, %d\n", diren->d_name, diren->d_fileno, diren->d_type);
    }
        
    closedir(dir);
    
    return 0;
}