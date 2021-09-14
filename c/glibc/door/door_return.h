/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 11日 星期四 08:58:35 CST. */

#include <door.h>

/**
 *	when a server procedure is done it returns by calling door_return.
 *	this causes the associated door_call in the client to return.
 *	
 */
int door_return(char *dataptr, size_t datasize, door_desc_t *descptr, size_t ndesc);



