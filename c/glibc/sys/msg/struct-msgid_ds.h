/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:16 CST. */



struct msgid_ds {
	struct ipc_perm	msg_perm;	//read-write perms
	struct msg *msg_first;
	struct msg *msg_lase;
	msglen_t msg_cbytes;
	msgqnum_t	msg_qnum;
	msglen_t	msgqbytes;
	pid_t		msg_lspid;
	pid_t		msg_lrpid;
	time_t		msg_stime;
	time_t		msg_rtime;
	time_t		msg_ctime;
};
