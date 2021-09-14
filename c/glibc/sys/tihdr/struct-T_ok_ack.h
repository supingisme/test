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



struct T_ok_ack {
	t_scalar_t PRIM_type; /* T_OK_ACK */
	t_scalar_t CORRECT_prim; /* correct primitive */
};

//In case of an error, we terminate. Since we do not know what type of message we will receive, a union named T_primitives is defined as the union of all the possible requests and replies, and we allocate one of these that we use as the input buffer for the control information when we call getmsg.
