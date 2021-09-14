/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
struct group * getgrgid (gid t gid) [Function]
This function returns a pointer to a statically-allocated structure containing informa
tion about the group whose group ID is gid. This structure may be overwritten by
subsequent calls to getgrgid.
A null pointer indicates there is no group with ID gid.
int getgrgid_r (gid t gid, struct group *result_buf, char *buffer, [Function]
size t buflen, struct group **result)
This function is similar to getgrgid in that it returns information about the group
whose group ID is gid. However, it flls the user supplied structure pointed to by
result buf with the information instead of using a static buﬀer. The frst buﬂen
bytes of the additional buﬀer pointed to by buﬀer are used to contain additional
information, normally strings which are pointed to by the elements of the result
structure.
If a group with ID gid is found, the pointer returned in result points to the record
which contains the wanted data (i.e., result contains the value result buf ). If no group
is found or if an error occurred, the pointer returned in result is a null pointer. The
function returns zero or an error code. If the buﬀer buﬀer is too small to contain all
the needed information, the error code ERANGE is returned and errno is set to ERANGE.


*/
#include <stdio.h>
#include <grp.h>

int main()
{
    struct group *_group = getgrgid(getgid());
    
    printf("%s:%d:", _group->gr_name, _group->gr_gid);
    
    char **members = _group->gr_mem;
    
    int i = 0;
    while(members[i] != NULL)
    {
        printf("%s:", members[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}   