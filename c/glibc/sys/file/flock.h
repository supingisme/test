/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:26 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 09:12:09 CST. 
*/
/**
 *NAME
 *	flock - apply or remove an advisory lock on an open file
 *	应用或者移除一个打开文件的公告锁？？
 *
 *	advisory：n. 公告、报告
 *			  adj. 顾问的，劝告的，忠告的，提供咨询的
 *
 *SYNOPSIS
 *	#include <sys/file.h>
 *  int flock(int fd, int operation);
 */

#include <sys/file.h>

/* Operations for the `flock' call.  */
#define	LOCK_SH	1	/* Shared lock.  */
#define	LOCK_EX	2 	/* Exclusive lock.  */
#define	LOCK_UN	8	/* Unlock.  */

/* Can be OR'd in to one of the above.  */
#define	LOCK_NB	4	/* Don't block when locking.  */

//文件描述符锁
int flock(int fd, int operation);

//LOCK_SH  Place a shared lock.  More than one process may hold a shared lock for a  given  file  at  a
//        given time.
//
//LOCK_EX  Place  an exclusive lock.  Only one process may hold an exclusive lock for a given file at a
//        given time.
//
//LOCK_UN  Remove an existing lock held by this process.


/**
 *	sys_flock: - flock() system call.
 *	@fd: the file descriptor to lock.
 *	@cmd: the type of lock to apply.
 *
 *	Apply a %FL_FLOCK style lock to an open file descriptor.
 *	The @cmd can be one of:
 *
 *	- %LOCK_SH -- a shared lock.
 *	- %LOCK_EX -- an exclusive lock.
 *	- %LOCK_UN -- remove an existing lock.
 *	- %LOCK_MAND -- a 'mandatory' flock.
 *	  This exists to emulate Windows Share Modes.
 *
 *	%LOCK_MAND can be combined with %LOCK_READ or %LOCK_WRITE to allow other
 *	processes read and write access respectively.
 */
SYSCALL_DEFINE2(flock, unsigned int, fd, unsigned int, cmd)
{
	struct fd f = fdget(fd);
	struct file_lock *lock;
	int can_sleep, unlock;
	int error;

	error = -EBADF;
	if (!f.file)
		goto out;

	can_sleep = !(cmd & LOCK_NB);
	cmd &= ~LOCK_NB;
	unlock = (cmd == LOCK_UN);

	if (!unlock && !(cmd & LOCK_MAND) &&
	    !(f.file->f_mode & (FMODE_READ|FMODE_WRITE)))
		goto out_putf;

	lock = flock_make_lock(f.file, cmd, NULL);
	if (IS_ERR(lock)) {
		error = PTR_ERR(lock);
		goto out_putf;
	}

	if (can_sleep)
		lock->fl_flags |= FL_SLEEP;

	error = security_file_lock(f.file, lock->fl_type);
	if (error)
		goto out_free;

	if (f.file->f_op->flock)
		error = f.file->f_op->flock(f.file,
					  (can_sleep) ? F_SETLKW : F_SETLK,
					  lock);
	else
		error = locks_lock_file_wait(f.file, lock);

 out_free:
	locks_free_lock(lock);

 out_putf:
	fdput(f);
 out:
	return error;
}

