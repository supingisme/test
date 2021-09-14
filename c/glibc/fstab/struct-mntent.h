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

struct mntent [Data Type]
This structure is used with the getmntent, getmntent_t, addmntent, and hasmntopt
functions.

    char *mnt_fsname
        This element contains a pointer to a string describing the name of the
        special device from which the flesystem is mounted. It corresponds to
        the fs_spec element in struct fstab.
    char *mnt_dir
        This element points to a string describing the mount point of the flesys
        tem. It corresponds to the fs_file element in struct fstab.
    char *mnt_type
        mnt_type describes the flesystem type and is therefore equivalent to fs_
        vfstype in struct fstab. ‘mntent.h’ defnes a few symbolic names for
        some of the values this string can have. But since the kernel can support
        arbitrary flesystems it does not make much sense to give them symbolic
        names. If one knows the symbol name one also knows the flesystem name.
        Nevertheless here follows the list of the symbols provided in ‘mntent.h’.
        MNTTYPE_IGNORE
        This symbol expands to "ignore". The value is sometime
        used in ‘fstab’ fles to make sure entries are not used without
        removing them.
        MNTTYPE_NFS
        Expands to "nfs". Using this macro sometimes could make
        sense since it names the default NFS implementation, in case
        both version 2 and 3 are supported.
        MNTTYPE_SWAP
        This symbol expands to "swap". It names the special ‘fstab’
        entry which names one of the possibly multiple swap parti
        tions.
    char *mnt_opts
        The element contains a string describing the options used while mounting
        the flesystem. As for the equivalent element fs_mntops of struct fstab
        it is best to use the function getsubopt (see Section 25.3.12.1 [Parsing of
        Suboptions], page 676) to access the parts of this string.
        The ‘mntent.h’ fle defnes a number of macros with string values which
        correspond to some of the options understood by the kernel. There might
        be many more options which are possible so it doesn’t make much sense
        to rely on these macros but to be consistent here is the list:
        MNTOPT_DEFAULTS
        Expands to "defaults". This option should be used alone
        since it indicates all values for the customizable values are
        chosen to be the default.
        MNTOPT_RO
        Expands to "ro". See the FSTAB_RO value, it means the
        flesystem is mounted read-only.
        MNTOPT_RW
        Expand to "rw". See the FSTAB_RW value, it means the flesys
        tem is mounted with read and write permissions.
        MNTOPT_SUID
        Expands to "suid". This means that the SUID bit (see
        Section 29.4 [How an Application Can Change Persona],
        page 728) is respected when a program from the flesystem
        is started.
        MNTOPT_NOSUID
        Expands to "nosuid". This is the opposite of MNTOPT_SUID,
        the SUID bit for all fles from the flesystem is ignored.
        MNTOPT_NOAUTO
        Expands to "noauto". At startup time the mount program
        will ignore this entry if it is started with the -a option to
        mount all flesystems mentioned in the ‘fstab’ fle.
        As for the FSTAB_* entries introduced above it is important to use strcmp
        to check for equality.
    mnt_freq This elements corresponds to fs_freq and also specifes the frequency in
        days in which dumps are made.
    mnt_passno
        This element is equivalent to fs_passno with the same meaning which is
        uninteresting for all programs beside dump.
*/

#include <fstab.h>

struct mntent{
    char *mnt_fsname;
    char *mnt_dir;
    char *mnt_type; //mntent.h
    char *mnt_opts;
    
};
















