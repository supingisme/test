/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 09日 星期二 08:56:44 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 20日 星期三 08:38:34 CST. */


/**
 *	A process allocates a shared memory segment using shmget (“SHared Memory
 *	GET”). Its first parameter is an integer key that specifies which segment to create.
 *	Unrelated processes can access the same shared segment by specifying the same key
 *	value. Unfortunately, other processes may have also chosen the same fixed key, which
 *	could lead to conflict. Using the special constant IPC_PRIVATE as the key value guarantees
 *	that a brand new memory segment is created.
 *
 *	Its second parameter specifies the number of bytes in the segment. Because segments
 *	are allocated using pages, the number of actually allocated bytes is rounded up
 *	to an integral multiple of the page size.
 *	The third parameter is the bitwise or of flag values that specify options to shmget.
 *	The flag values include these:
 *	n IPC_CREAT—This flag indicates that a new segment should be created.This permits
 *	creating a new segment while specifying a key value.
 *	n IPC_EXCL—This flag, which is always used with IPC_CREAT, causes shmget to fail
 *	if a segment key is specified that already exists.Therefore, it arranges for the calling
 *	process to have an “exclusive” segment. If this flag is not given and the key
 *	of an existing segment is used, shmget returns the existing segment instead of
 *	creating a new one.
 *	n Mode flags—This value is made of 9 bits indicating permissions granted to
 *	owner, group, and world to control access to the segment. Execution bits are
 *	ignored. An easy way to specify permissions is to use the constants defined in
 *	<sys/stat.h> and documented in the section 2 stat man page.1 For example,
 *	S_IRUSR and S_IWUSR specify read and write permissions for the owner of the
 *	shared memory segment, and S_IROTH and S_IWOTH specify read and write permissions
 *	for others.
 *	For example, this invocation of shmget creates a new shared memory segment (or
 *	access to an existing one, if shm_key is already used) that’s readable and writeable to
 *	the owner but not other users.
 *	int segment_id = shmget (shm_key, getpagesize (), IPC_CREAT | S_IRUSR | S_IWUSER);
 */

#include <sys/ipc.h>
#include <sys/shm.h>

int shmget(key_t key, size_t size, int shmflg);

int segment_id = shmget (shm_key, getpagesize (), IPC_CREAT | S_IRUSR | S_IWUSER);

SYSCALL_DEFINE3(shmget, key_t, key, size_t, size, int, shmflg)
{
	return ksys_shmget(key, size, shmflg);
}

