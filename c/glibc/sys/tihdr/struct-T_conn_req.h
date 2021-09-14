/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:31 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 08:35:32 CST. */


#include <sys/tihdr.h>

struct T_conn_req {
	t_scalar_t PRIM_type; /* T_CONN_REQ */
	t_scalar_t DEST_length; /* destination address length */
	t_scalar_t DEST_offset; /* destination address offset */
	t_scalar_t OPT_length; /* options length */
	t_scalar_t OPT_offset; /* options offset */
	/* followed by the protocol address and options for connection */
};

//As in our tpi_bind function, we define our own structure named conn_req, which includes a T_conn_req structure along with room for the protocol address. We fill in our conn_req structure, setting the two members dealing with options to 0. We call putmsg with only control information and a flag of 0 to send an M_PROTO message down the stream.
//
//
