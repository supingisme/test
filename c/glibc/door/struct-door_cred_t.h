/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 11日 星期四 08:58:35 CST. */

typedef struct door_cred {
	uid_t	dc_euid;	//effective user ID of client
	git_t	dc_egit;	//effective group ID of client
	uid_t	dc_rgid;	//real user ID of client
	git_t	dc_rgid;	//real group ID of client
	pid_t	dc_pid;		//process ID of client
}door_cred_t;
