/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:25 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 09:35:20 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 09:35:15 CST. */


#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

mqd_t mq_open(const char *name, int oflag);
mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);

//Link with -lrt.

//O_RDONLY
//		Open the queue to receive messages only.
//
//O_WRONLY
//		Open the queue to send messages only.
//
//O_RDWR Open the queue to both send and receive messages.
//
//		Zero or more of the following flags can additionally be ORed in oflag:
//
//O_NONBLOCK
//		Open the  queue  in  nonblocking  mode.   In  circumstances  where  mq_receive(3)  and
//		mq_send(3) would normally block, these functions instead fail with the error EAGAIN.
//
//O_CREAT
//		Create  the  message  queue  if it does not exist.  The owner (user ID) of the message
//		queue is set to the effective user ID of the calling  process.   The  group  ownership
//		(	group ID) is set to the effective group ID of the calling process.
//
//O_EXCL If  O_CREAT  was  specified  in oflag, and a queue with the given name already exists,
//			then fail with the error EEXIST.
//


SYSCALL_DEFINE4(mq_open, const char __user *, u_name, int, oflag, umode_t, mode,
		struct mq_attr __user *, u_attr)
{
	struct mq_attr attr;
	if (u_attr && copy_from_user(&attr, u_attr, sizeof(struct mq_attr)))
		return -EFAULT;

	return do_mq_open(u_name, oflag, mode, u_attr ? &attr : NULL);
}

