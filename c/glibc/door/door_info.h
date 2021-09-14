/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 11日 星期四 08:58:35 CST. */


#include <door.h>

/**
 *	the door_info function that we just described provides information for 
 *	the server about the client. the client can find information about the server 
 *	by calling the door_info function
 */
int door_info(int fd, door_info_t *info);




typedef struct door_info {
	pid_t		di_target;		//server processID
	door_ptr_t	di_proc;		//server procedure
	door_ptr_t	di_data;		//cookie for server procedure
	door_attr_t	di_attribute;	//attributes associated with door
	door_id_t	di_uniquifier;	//unique number
}door_info_t;
