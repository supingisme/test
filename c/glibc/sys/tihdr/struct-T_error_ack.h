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

struct T_error_ack {
	t_scalar_t PRIM_type; /* T_ERROR_ACK */
	t_scalar_t ERROR_prim /* primitive in error */
		t_scalar_t TLI_error; /* TLI error code */
	t_scalar_t UNIX_error; /* UNIX error code */
};


//All these messages begin with the type, so we can read the reply assuming it is a T_BIND_ACK message, look at the type, and process the message accordingly. We do not expect any data from the provider, so we specify a null pointer as the third argument to getmsg.
//When we verify that the amount of control information returned is at least the size of a long integer, we must be careful to cast the sizeof value to an integer. The sizeof operator returns an unsigned integer value, but it is possible for the returned len field to be –1. But since the less-than comparison is comparing a signed value on the left to an unsigned value on the right, the compiler casts the signed value to an unsigned value. On a two's-complement architecture, –1, considered as an unsigned value, is very large, causing –1 to be greater than 4 (if we assume a long integer occupies 4 bytes).
//
//
