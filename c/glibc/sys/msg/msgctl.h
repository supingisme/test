/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 22日 星期五 08:33:24 CST. */
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
//NAME
//msgctl - System V message control operations
//SYNOPSIS
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int msgctl(int msqid, int cmd, struct msqid_ds *buf);

/**
 * *	msgctl函数提供在一个消息队列上的各种操作
 * */

#include <sys/msg.h>

int msgctl(int msqid, int cmd, struct msqid_ds *buff);
/**
 * *	返回：	
 * *		成功：0
 * *		错误：-1
 * *
 * *	msgctl函数提供3个命令：
 * *		IPC_RMID	从系统中删除由msqid指定的消息队列
 * *		IPC_SET		给所有指定的消息队列设置其msqid_ds结构的一下四个成员：
 * *					msg_perm.uid	msg_perm.gid	msg_perm.mode
 * *					msg_perm.qbytes
 * *		IPC_STAT	（通过buff参数）给调用者返回与所指定消息队列对应的当前
 * *					msqid_ds结构。
 * */

//Usage
int msgid = msgget(IPC_PRIVATE, SVMSG_MODE|IPC_CREAT);
struct msgid_ds info;
struct msgbuf buf;

buf.mtype = 1;
buf.mtext[0] = 1;
msgsnd(msgid, &buf, 1, 0);
msgctl(msgid, IPC_STAT, &info);

printf("read-write: %03o, cbytes = %lu, qnum = %lu, qbytes = %lu\n",
		info.msg_perm.mode&0777, 
		(ulong_t) info.msg_cbytes,
		(ulong_t) info.msg_qnum,
		(ulong_t) info.msg_qbytes);

system("ipcs -q");

msgctl(msgid, IPC_RMID, NULL);



