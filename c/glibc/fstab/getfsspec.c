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


struct fstab * getfsspec (const char *name) [Function]
This function returns the next entry of the ‘fstab’ fle which has a string equal to
name pointed to by the fs_spec element. Since there is normally exactly one entry
for each special device it makes no sense to call this function more than once for the
same argument. If this is the frst call to any of the functions handling ‘fstab’ since
program start or the last call of endfsent, the fle will be opened.
The function returns a pointer to a variable of type struct fstab. This variable
is shared by all threads and therefore this function is not thread-safe. If an error
occurred getfsent returns a NULL pointer.



 */

#include <fstab.h>
#include <stdio.h>

int main()
{
	setfsent();

	struct fstab *fstab = getfsspec("/dev/mapper/centos-root");

	printf("%s:%s:%s:%s:%s:%d:%d\n",
			fstab->fs_spec, fstab->fs_file,
			fstab->fs_vfstype, fstab->fs_mntops,
			fstab->fs_type, fstab->fs_freq, fstab->fs_passno);

	return 0;
}
