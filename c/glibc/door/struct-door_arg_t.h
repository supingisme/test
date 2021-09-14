/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 11日 星期四 08:58:35 CST. */

#include <door.h>

typedef struct door_arg{
	char		*data_ptr;	//data arguments
	size_t		data_size;	//size of data argument
	door_desc_t	*desc_ptr;	//
	size_t		desc_num;	//
	char		*rbuf;		//data result
	size_t		rsize;		//size of data result
}door_arg_t ;


