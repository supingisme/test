/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:16 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 09:49:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 09:49:24 CST. */


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgget(key_t key, int msgflg);

/**
 * *	msgget函数用于创建一个新的消息队列或访问一个已存在的消息队列
 * */

#include <sys/msg.h>

int msgget(key_t key, int oflag);
//成功：非负标识符
////错误：-1
///**
//*	key：可以使ftok返回值，也可以是IPC_PROVATE
//*	oflag：读写权限值的组合
//*/

SYSCALL_DEFINE2(msgget, key_t, key, int, msgflg)
{
	return ksys_msgget(key, msgflg);
}

long ksys_msgget(key_t key, int msgflg)
{
	struct ipc_namespace *ns;
	static const struct ipc_ops msg_ops = {
		.getnew = newque,
		.associate = security_msg_queue_associate,
	};
	struct ipc_params msg_params;

	ns = current->nsproxy->ipc_ns;

	msg_params.key = key;
	msg_params.flg = msgflg;

	return ipcget(ns, &msg_ids(ns), &msg_ops, &msg_params);
}

