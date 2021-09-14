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
int chdir (const char *filename) [Function]
This function is used to set the process’s working directory to flename.
The normal, successful return value from chdir is 0. A value of -1 is returned to
indicate an error. The errno error conditions defned for this function are the usual
fle name syntax errors (see Section 11.2.3 [File Name Errors], page 224), plus ENOTDIR
if the fle flename is not a directory

RongTao  Wallpaper
/home
a.out	clean.sh  ipc	     perl5	str_to_0x.c   target.cap  top_pid.sh
bak.sh	gtk	  jt_sran.8  pstree.sh	str_to_0x.c~  test	  wys_sbs
/home/RongTao


*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    chdir("/home/");
    
    system("ls; pwd");
    
    chdir("/home/RongTao/");
    
    system("ls; pwd");
    
    return 0;
}