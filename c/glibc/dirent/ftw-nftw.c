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
14.3 Working with Directory Trees
The functions described so far for handling the fles in a directory have allowed you to either
retrieve the information bit by bit, or to process all the fles as a group (see scandir).
Sometimes it is useful to process whole hierarchies of directories and their contained fles.
The X/Open specifcation defnes two functions to do this. The simpler form is derived
from an early defnition in System V systems and therefore this function is available on
SVID-derived systems. The prototypes and required defnitions can be found in the ‘ftw.h’
header.
There are four functions in this family: ftw, nftw and their 64-bit counterparts ftw64
and nftw64. These functions take as one of their arguments a pointer to a callback function
of the appropriate type.
__ftw_func_t [Data Type]
int (*) (const char *, const struct stat *, int)
The type of callback functions given to the ftw function. The frst parameter points
to the fle name, the second parameter to an object of type struct stat which is
flled in for the fle named in the frst parameter.
The last parameter is a ﬂag giving more information about the current fle. It can
have the following values:
FTW_F The item is either a normal fle or a fle which does not ft into one of the
following categories. This could be special fles, sockets etc.
FTW_D The item is a directory.
FTW_NS The stat call failed and so the information pointed to by the second
paramater is invalid.
FTW_DNR The item is a directory which cannot be read.
FTW_SL The item is a symbolic link. Since symbolic links are normally followed
seeing this value in a ftw callback function means the referenced fle does
not exist. The situation for nftw is diﬀerent.

This value is only available if the program is compiled with _BSD_SOURCE
or _XOPEN_EXTENDED defned before including the frst header. The orig
inal SVID systems do not have symbolic links.
If the sources are compiled with _FILE_OFFSET_BITS == 64 this type is in fact __
ftw64_func_t since this mode changes struct stat to be struct stat64.
For the LFS interface and for use in the function ftw64, the header ‘ftw.h’ defnes
another function type.
__ftw64_func_t [Data Type]
int (*) (const char *, const struct stat64 *, int)
This type is used just like __ftw_func_t for the callback function, but this time is
called from ftw64. The second parameter to the function is a pointer to a variable of
type struct stat64 which is able to represent the larger values.
__nftw_func_t [Data Type]
int (*) (const char *, const struct stat *, int, struct FTW *)
The frst three arguments are the same as for the __ftw_func_t type. However for
the third argument some additional values are defned to allow fner diﬀerentiation:
FTW_DP The current item is a directory and all subdirectories have already been
visited and reported. This ﬂag is returned instead of FTW_D if the FTW_
DEPTH ﬂag is passed to nftw (see below).
FTW_SLN The current item is a stale symbolic link. The fle it points to does not
exist.
The last parameter of the callback function is a pointer to a structure with some extra
information as described below.
If the sources are compiled with _FILE_OFFSET_BITS == 64 this type is in fact __
nftw64_func_t since this mode changes struct stat to be struct stat64.
For the LFS interface there is also a variant of this data type available which has to be
used with the nftw64 function.
__nftw64_func_t [Data Type]
int (*) (const char *, const struct stat64 *, int, struct FTW *)
This type is used just like __nftw_func_t for the callback function, but this time is
called from nftw64. The second parameter to the function is this time a pointer to a
variable of type struct stat64 which is able to represent the larger values.
struct FTW [Data Type]
The information contained in this structure helps in interpreting the name parameter
and gives some information about the current state of the traversal of the directory
hierarchy.
int base The value is the oﬀset into the string passed in the frst parameter to the
callback function of the beginning of the fle name. The rest of the string
is the path of the fle. This information is especially important if the
FTW_CHDIR ﬂag was set in calling nftw since then the current directory is
the one the current item is found in.

int level Whilst processing, the code tracks how many directories down it has gone
to fnd the current fle. This nesting level starts at 0 for fles in the initial
directory (or is zero for the initial fle if a fle was passed).
int ftw (const char *filename, ftw func t func, int descriptors) [Function]
The ftw function calls the callback function given in the parameter func for every
item which is found in the directory specifed by flename and all directories below.
The function follows symbolic links if necessary but does not process an item twice.
If flename is not a directory then it itself is the only object returned to the callback
function.
The fle name passed to the callback function is constructed by taking the flename
parameter and appending the names of all passed directories and then the local fle
name. So the callback function can use this parameter to access the fle. ftw also
calls stat for the fle and passes that information on to the callback function. If this
stat call was not successful the failure is indicated by setting the third argument of
the callback function to FTW_NS. Otherwise it is set according to the description given
in the account of __ftw_func_t above.
The callback function is expected to return 0 to indicate that no error occurred and
that processing should continue. If an error occurred in the callback function or
it wants ftw to return immediately, the callback function can return a value other
than 0. This is the only correct way to stop the function. The program must not
use setjmp or similar techniques to continue from another place. This would leave
resources allocated by the ftw function unfreed.
The descriptors parameter to ftw specifes how many fle descriptors it is allowed to
consume. The function runs faster the more descriptors it can use. For each level in
the directory hierarchy at most one descriptor is used, but for very deep ones any limit
on open fle descriptors for the process or the system may be exceeded. Moreover,
fle descriptor limits in a multi-threaded program apply to all the threads as a group,
and therefore it is a good idea to supply a reasonable limit to the number of open
descriptors.
The return value of the ftw function is 0 if all callback function calls returned 0 and
all actions performed by the ftw succeeded. If a function call failed (other than calling
stat on an item) the function returns −1. If a callback function returns a value other
than 0 this value is returned as the return value of ftw.
When the sources are compiled with _FILE_OFFSET_BITS == 64 on a 32-bit system
this function is in fact ftw64, i.e., the LFS interface transparently replaces the old
interface.
int ftw64 (const char *filename, ftw64 func t func, int [Function]
descriptors)
This function is similar to ftw but it can work on flesystems with large fles. File
information is reported using a variable of type struct stat64 which is passed by
reference to the callback function.
When the sources are compiled with _FILE_OFFSET_BITS == 64 on a 32-bit system
this function is available under the name ftw and transparently replaces the old
implementation.

int nftw (const char *filename, nftw func t func, int descriptors, [Function]
int flag)
The nftw function works like the ftw functions. They call the callback function func
for all items found in the directory flename and below. At most descriptors fle
descriptors are consumed during the nftw call.
One diﬀerence is that the callback function is of a diﬀerent type. It is of type
struct FTW * and provides the callback function with the extra information described
above.
A second diﬀerence is that nftw takes a fourth argument, which is 0 or a bitwise-OR
combination of any of the following values.
FTW_PHYS While traversing the directory symbolic links are not followed. Instead
symbolic links are reported using the FTW_SL value for the type parameter
to the callback function. If the fle referenced by a symbolic link does not
exist FTW_SLN is returned instead.
FTW_MOUNT
The callback function is only called for items which are on the same
mounted flesystem as the directory given by the flename parameter to
nftw.
FTW_CHDIR
If this ﬂag is given the current working directory is changed to the direc
tory of the reported object before the callback function is called. When
ntfw fnally returns the current directory is restored to its original value.
FTW_DEPTH
If this option is specifed then all subdirectories and fles within them
are processed before processing the top directory itself (depth-frst pro
cessing). This also means the type ﬂag given to the callback function is
FTW_DP and not FTW_D.
FTW_ACTIONRETVAL
If this option is specifed then return values from callbacks are handled
diﬀerently. If the callback returns FTW_CONTINUE, walking continues nor
mally. FTW_STOP means walking stops and FTW_STOP is returned to the
caller. If FTW_SKIP_SUBTREE is returned by the callback with FTW_D ar
gument, the subtree is skipped and walking continues with next sibling
of the directory. If FTW_SKIP_SIBLINGS is returned by the callback, all
siblings of the current entry are skipped and walking continues in its par
ent. No other return values should be returned from the callbacks if this
option is set. This option is a GNU extension.
The return value is computed in the same way as for ftw. nftw returns 0 if no
failures occurred and all callback functions returned 0. In case of internal errors, such
as memory problems, the return value is −1 and errno is set accordingly. If the return
value of a callback invocation was non-zero then that value is returned.
When the sources are compiled with _FILE_OFFSET_BITS == 64 on a 32-bit system
this function is in fact nftw64, i.e., the LFS interface transparently replaces the old
interface.

int nftw64 (const char *filename, nftw64 func t func, int [Function]
descriptors, int flag)
This function is similar to nftw but it can work on flesystems with large fles. File
information is reported using a variable of type struct stat64 which is passed by
reference to the callback function.
When the sources are compiled with _FILE_OFFSET_BITS == 64 on a 32-bit system
this function is available under the name nftw and transparently replaces the old
implementation.

*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <ftw.h>
#include <errno.h>
#include <malloc.h>

#define _XOPEN_SOURCE 500
#define __USE_XOPEN_EXTENDED

struct FTW{
    int base;
    int level;
};

static int display_info_nftw(
    const char *fpath, 
    const struct stat *sb, 
    int tflag, 
    struct FTW *ftwbuf)
{
    printf("%-3s %2d ", (tflag == FTW_D)?"d":
                        (tflag == FTW_DNR)?"dnr":
                        (tflag == 5/*FTW_DP*/)?"dp":
                        (tflag == FTW_F)?"f":
                        (tflag == FTW_NS)?"ns":
                        (tflag == FTW_SL)?"sl":
                        (tflag == 6/*FTW_SLN*/)?"sln":"???", ftwbuf->level);
                        
    if(tflag == FTW_NS)
    {
        printf("-------");
    }
    else
    {
        printf("%7jd", (intmax_t)sb->st_size);
    }
    printf("   %-40s %3d %s\n", fpath, ftwbuf->base, fpath+ftwbuf->base);
    
    return 0;
}


int main(int argc, char *argv[])
{
    int flags = 0;
    
    if(argc > 2 && strchr(argv[2], 'd') != NULL)
    {
        flags |= 8/*FTW_DEPTH*/;
    }
    if(argc > 2 && strchr(argv[2], 'p') != NULL)
    {
        flags |= 1;/*FTW_PHYS*/;
    }
    
    if(nftw((argc <2)?".":argv[1], display_info_nftw, 20, flags))
    {
        perror("nftw");
        exit(1);
    }
    
    return 0;
}
