/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*	14.9.5 The Mode Bits for Access Permission
 *	The fle mode, stored in the st_mode feld of the fle attributes, contains two kinds of
 *	information: the fle type code, and the access permission bits. This section discusses only
 *	the access permission bits, which control who can read or write the fle. See Section 14.9.3
 *	[Testing the Type of a File], page 367, for information about the fle type code.
 *	All of the symbols listed in this section are defned in the header fle ‘sys/stat.h’.
 *	These symbolic constants are defned for the fle mode bits that control access permission
 *	for the fle:
 *	S_IRUSR
 *	S_IREAD Read permission bit for the owner of the fle. On many systems this bit is 0400.
 *	S_IREAD is an obsolete synonym provided for BSD compatibility.
 *	S_IWUSR
 *	S_IWRITE Write permission bit for the owner of the fle. Usually 0200. S_IWRITE is an
 *	obsolete synonym provided for BSD compatibility.
 *
 *	S_IXUSR
 *	S_IEXEC Execute (for ordinary fles) or search (for directories) permission bit for the
 *	owner of the fle. Usually 0100. S_IEXEC is an obsolete synonym provided for
 *	BSD compatibility.
 *	S_IRWXU This is equivalent to ‘(S_IRUSR | S_IWUSR | S_IXUSR)’.
 *	S_IRGRP Read permission bit for the group owner of the fle. Usually 040.
 *	S_IWGRP Write permission bit for the group owner of the fle. Usually 020.
 *	S_IXGRP Execute or search permission bit for the group owner of the fle. Usually 010.
 *	S_IRWXG This is equivalent to ‘(S_IRGRP | S_IWGRP | S_IXGRP)’.
 *	S_IROTH Read permission bit for other users. Usually 04.
 *	S_IWOTH Write permission bit for other users. Usually 02.
 *	S_IXOTH Execute or search permission bit for other users. Usually 01.
 *	S_IRWXO This is equivalent to ‘(S_IROTH | S_IWOTH | S_IXOTH)’.
 *	S_ISUID This is the set-user-ID on execute bit, usually 04000. See Section 29.4 [How an
 *	Application Can Change Persona], page 728.
 *	S_ISGID This is the set-group-ID on execute bit, usually 02000. See Section 29.4 [How
 *	an Application Can Change Persona], page 728.
 *	S_ISVTX This is the sticky bit, usually 01000.
 *	For a directory it gives permission to delete a fle in that directory only if you
 *	own that fle. Ordinarily, a user can either delete all the fles in a directory
 *	or cannot delete any of them (based on whether the user has write permission
 *	for the directory). The same restriction applies—you must have both write
 *	permission for the directory and own the fle you want to delete. The one
 *	exception is that the owner of the directory can delete any fle in the directory,
 *	no matter who owns it (provided the owner has given himself write permission
 *	for the directory). This is commonly used for the ‘/tmp’ directory, where anyone
 *	may create fles but not delete fles created by other users.
 *	Originally the sticky bit on an executable fle modifed the swapping policies
 *	of the system. Normally, when a program terminated, its pages in core were
 *	immediately freed and reused. If the sticky bit was set on the executable fle,
 *	the system kept the pages in core for a while as if the program were still running.
 *	This was advantageous for a program likely to be run many times in succession.
 *	This usage is obsolete in modern systems. When a program terminates, its pages
 *	always remain in core as long as there is no shortage of memory in the system.
 *	When the program is next run, its pages will still be in core if no shortage arose
 *	since the last run.
 *	On some modern systems where the sticky bit has no useful meaning for an
 *	executable fle, you cannot set the bit at all for a non-directory. If you try, chmod
 *	fails with EFTYPE; see Section 14.9.7 [Assigning File Permissions], page 372.
 *	Some systems (particularly SunOS) have yet another use for the sticky bit. If
 *	the sticky bit is set on a fle that is not executable, it means the opposite: never
 *
 */
#include <sys/stat.h>
