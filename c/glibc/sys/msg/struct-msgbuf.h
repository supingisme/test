/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:16 CST. */


struct msgbuf {
	long mtype;	//message type, must be > 0
	char mtext[1];	//message data.
};
