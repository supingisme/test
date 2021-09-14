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

//register for notification when a message is available
#include <mqueue.h>

int mq_notify(mqd_t mqdes, const struct sigevent *sevp);

//Link with -lrt.


SYSCALL_DEFINE2(mq_notify, mqd_t, mqdes,
		const struct sigevent __user *, u_notification)
{
	struct sigevent n, *p = NULL;
	if (u_notification) {
		if (copy_from_user(&n, u_notification, sizeof(struct sigevent)))
			return -EFAULT;
		p = &n;
	}
	return do_mq_notify(mqdes, p);
}

