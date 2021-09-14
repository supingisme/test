/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 11日 星期四 08:58:35 CST. */

/*
 *	the door_call function is called by a client, and it calls a server procedure that is executing
 *	in the address space of the server process.
 *
 */
#include <door.h>

int door_call(int doorfd, door_arg_t *argp);



