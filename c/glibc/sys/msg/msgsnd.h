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




/**
 * *	用msgget打开一个消息队列后，我们使用msgsnd往其上放置一个消息
 * */

#include <sys/msg.h>

int msgsnd(int msgid, const void *ptr, size_t length, int flag);
//成功：0
////错误：-1
///**
//*	msgid：由msgget返回的标识符
//*	ptr：一个结构体指针，他有如下的模板，定义在sys/msg.h里面
//*		struct msgbuf{
//*			long mtype;
//*			char mtext[1];
//*		};
//*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
		int msgflg);

/**
 * *	使用msgrcv函数从某个消息队列中读取一个消息
 * */

#include <sys/msg.h>

ssize_t msgrcv(int msqid, void *ptr, size_t length, long type, int flag);
//成功：返回读入缓冲区中数据的字节数
////错误：-1
///**
//*	ptr：指定所接收消息存放位置
//*	length：制定了由ptr指向缓冲区中数据部分的大小，这是函数能返回的最大数据量。
//*			该长度不包括长整数类型字段。
//*	type：指定希望从所给定的队列中读出什么样的消息。
//*/
//
