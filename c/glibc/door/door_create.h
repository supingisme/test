/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 11日 星期四 08:58:35 CST. */

#include <door.h>

typedef void Door_server_proc(void *cookie, char *dataptr, size_t datasize,
								door_desc_t *descptr, size_t ndesc);

/**
 *	a server process establishes a server procedure by calling door_create.
 *
 */
int door_create(Door_server_proc *proc, void *cookie, u_int attr);



