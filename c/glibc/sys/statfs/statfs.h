/* Definitions for getting information about a filesystem.
   Copyright (C) 1996-1999, 2004, 2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef	_SYS_STATFS_H
#define	_SYS_STATFS_H	1

#include <features.h>

#ifndef __rtoax_debug
struct statfs {
	short	f_type;			/* filesystem type number */
	short	f_flags;		/* copy of mount flags */
	long	f_bsize;		/* fundamental file system block size */
	long	f_iosize;		/* optimal transfer block size */
	long	f_blocks;		/* total data blocks in file system */
	long	f_bfree;		/* free blocks in fs */
	long	f_bavail;		/* free blocks avail to non-superuser */
	long	f_files;		/* total file nodes in file system */
	long	f_ffree;		/* free file nodes in fs */
	fsid_t	f_fsid;			/* file system id */
	uid_t	f_owner;		/* user that mounted the filesystem */
	long	f_spare[4];		/* spare for later */
	char	f_fstypename[MFSNAMELEN]; /* fs type name */
	char	f_mntonname[MNAMELEN];	/* directory on which mounted */
	char	f_mntfromname[MNAMELEN];/* mounted filesystem */
};

#if __WORDSIZE == 32          /* System word size */
# define __SWORD_TYPE           int
#else /* __WORDSIZE == 64 */
# define __SWORD_TYPE         long int
#endif

struct statfs {
    __SWORD_TYPE f_type;    /* type of file system (see below) */
    __SWORD_TYPE f_bsize;   /* optimal transfer block size */
    fsblkcnt_t   f_blocks;  /* total data blocks in file system */
    fsblkcnt_t   f_bfree;   /* free blocks in fs */
    fsblkcnt_t   f_bavail;  /* free blocks available to
                               unprivileged user */
    fsfilcnt_t   f_files;   /* total file nodes in file system */
    fsfilcnt_t   f_ffree;   /* free file nodes in fs */
    fsid_t       f_fsid;    /* file system id */
    __SWORD_TYPE f_namelen; /* maximum length of filenames */
    __SWORD_TYPE f_frsize;  /* fragment size (since Linux 2.6) */
    __SWORD_TYPE f_spare[5];
};
//File system types:
//
#define   ADFS_SUPER_MAGIC      0xadf5
#define   AFFS_SUPER_MAGIC      0xADFF
#define   BEFS_SUPER_MAGIC      0x42465331
#define   BFS_MAGIC             0x1BADFACE
#define   CIFS_MAGIC_NUMBER     0xFF534D42
#define   CODA_SUPER_MAGIC      0x73757245
#define   COH_SUPER_MAGIC       0x012FF7B7
#define   CRAMFS_MAGIC          0x28cd3d45
#define   DEVFS_SUPER_MAGIC     0x1373
#define   EFS_SUPER_MAGIC       0x00414A53
#define   EXT_SUPER_MAGIC       0x137D
#define   EXT2_OLD_SUPER_MAGIC  0xEF51
#define   EXT2_SUPER_MAGIC      0xEF53
#define   EXT3_SUPER_MAGIC      0xEF53
#define   EXT4_SUPER_MAGIC      0xEF53
#define   HFS_SUPER_MAGIC       0x4244
#define   HPFS_SUPER_MAGIC      0xF995E849
#define   HUGETLBFS_MAGIC       0x958458f6
#define   ISOFS_SUPER_MAGIC     0x9660
#define   JFFS2_SUPER_MAGIC     0x72b6
#define   JFS_SUPER_MAGIC       0x3153464a
#define   MINIX_SUPER_MAGIC     0x137F /* orig. minix */
#define   MINIX_SUPER_MAGIC2    0x138F /* 30 char minix */
#define   MINIX2_SUPER_MAGIC    0x2468 /* minix V2 */
#define   MINIX2_SUPER_MAGIC2   0x2478 /* minix V2, 30 char names */
#define   MSDOS_SUPER_MAGIC     0x4d44
#define   NCP_SUPER_MAGIC       0x564c
#define   NFS_SUPER_MAGIC       0x6969
#define   NTFS_SB_MAGIC         0x5346544e
#define   OPENPROM_SUPER_MAGIC  0x9fa1
#define   PROC_SUPER_MAGIC      0x9fa0
#define   QNX4_SUPER_MAGIC      0x002f
#define   REISERFS_SUPER_MAGIC  0x52654973
#define   ROMFS_MAGIC           0x7275
#define   SMB_SUPER_MAGIC       0x517B
#define   SYSV2_SUPER_MAGIC     0x012FF7B6
#define   SYSV4_SUPER_MAGIC     0x012FF7B5
#define   TMPFS_MAGIC           0x01021994
#define   UDF_SUPER_MAGIC       0x15013346
#define   UFS_MAGIC             0x00011954
#define   USBDEVICE_SUPER_MAGIC 0x9fa2
#define   VXFS_SUPER_MAGIC      0xa501FCF5
#define   XENIX_SUPER_MAGIC     0x012FF7B4
#define   XFS_SUPER_MAGIC       0x58465342
#define   _XIAFS_SUPER_MAGIC    0x012FD16D

#endif //__rtoax_debug

/* Get the system-specific definition of `struct statfs'.  */
#include <bits/statfs.h>

__BEGIN_DECLS

/* Return information about the filesystem on which FILE resides.  */
#ifndef __USE_FILE_OFFSET64
extern int statfs (const char *__file, struct statfs *__buf)
     __THROW __nonnull ((1, 2));
#else
# ifdef __REDIRECT_NTH
extern int __REDIRECT_NTH (statfs,
			   (const char *__file, struct statfs *__buf),
			   statfs64) __nonnull ((1, 2));
# else
#  define statfs statfs64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern int statfs64 (const char *__file, struct statfs64 *__buf)
     __THROW __nonnull ((1, 2));
#endif

/* Return information about the filesystem containing the file FILDES
   refers to.  */
#ifndef __USE_FILE_OFFSET64
extern int fstatfs (int __fildes, struct statfs *__buf)
     __THROW __nonnull ((2));
#else
# ifdef __REDIRECT_NTH
extern int __REDIRECT_NTH (fstatfs, (int __fildes, struct statfs *__buf),
			   fstatfs64) __nonnull ((2));
# else
#  define fstatfs fstatfs64
# endif
#endif
#ifdef __USE_LARGEFILE64
extern int fstatfs64 (int __fildes, struct statfs64 *__buf)
     __THROW __nonnull ((2));
#endif

__END_DECLS

#endif	/* sys/statfs.h */
