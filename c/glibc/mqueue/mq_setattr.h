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

#include <mqueue.h>

int mq_getattr(mqd_t mqdes, struct mq_attr *attr);

int mq_setattr(mqd_t mqdes, struct mq_attr *newattr, struct mq_attr *oldattr);

//Link with -lrt.
//

struct mq_attr {
	long mq_flags;       /* Flags: 0 or O_NONBLOCK */
	long mq_maxmsg;      /* Max. # of messages on queue */
	long mq_msgsize;     /* Max. message size (bytes) */
	long mq_curmsgs;     /* # of messages currently in queue */
};



SYSCALL_DEFINE3(mq_getsetattr, mqd_t, mqdes,
		const struct mq_attr __user *, u_mqstat,
		struct mq_attr __user *, u_omqstat)
{
	int ret;
	struct mq_attr mqstat, omqstat;
	struct mq_attr *new = NULL, *old = NULL;

	if (u_mqstat) {
		new = &mqstat;
		if (copy_from_user(new, u_mqstat, sizeof(struct mq_attr)))
			return -EFAULT;
	}
	if (u_omqstat)
		old = &omqstat;

	ret = do_mq_getsetattr(mqdes, new, old);
	if (ret || !old)
		return ret;

	if (copy_to_user(u_omqstat, old, sizeof(struct mq_attr)))
		return -EFAULT;
	return 0;
}

