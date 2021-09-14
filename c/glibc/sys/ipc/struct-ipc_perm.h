/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */


/* Data structure used to pass permission information to IPC operations.  */
struct ipc_perm
{
	__key_t __key;			/* Key.  */
	__uid_t uid;			/* Owner's user ID.  */
	__gid_t gid;			/* Owner's group ID.  */
	__uid_t cuid;			/* Creator's user ID.  */
	__gid_t cgid;			/* Creator's group ID.  */
	unsigned short int mode;		/* Read/write permission.  */
	unsigned short int __pad1;
	unsigned short int __seq;		/* Sequence number.  */
	unsigned short int __pad2;
	__syscall_ulong_t __unused1;
	__syscall_ulong_t __unused2;
};


struct ipc_perm {
	uid_t uid; /* owner's user i d */
	gid_t gid; /* owner's group id */
	uid_t cuid; /* c r e a t o r ' s user i d */
	gid_t cgid; /* c r e a t o r ' s group i d */
	mode_t mode; /* read-write permissions */
	ulong_t seq; /* s l o t usage sequence number */
	key_t key; /* IPC key */
};


//This structure, and other manifest constants for the System V IPC functions, are defined
//in the <sys/ipc .h> header. We talk about all the members of this structure in this
//chapter.
