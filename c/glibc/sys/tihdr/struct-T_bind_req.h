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

struct T_bind_req {
	t_scalar_t PRIM_type; /* T_BIND_REQ */
	t_scalar_t ADDR_length; /* address length */
	t_scalar_t ADDR_offset; /* address offset */
	t_uscalar_t CONIND_number; /* connect indications requested */
	/* followed by the protocol address for bind */
};
//All TPI requests are defined as a structure that begins with a long integer type field. We define our own bind_req structure that begins with the T_bind_req structure, followed by a buffer containing the local address to be bound. TPI says nothing about the contents of this buffer; it is defined by the provider. TCP providers expect this buffer to contain a sockaddr_in structure.
//We fill in the T_bind_req structure, setting the ADDR_length member to the size of the address (16 bytes for an Internet socket address structure) and ADDR_offset to the byte offset of the address (it immediately follows the T_bind_req structure). We are not guaranteed that this location is suitably aligned for the sockaddr_in structure that is stored there, so we call memcpy to copy the caller's structure into our bind_req structure. We set CONIND_number to 0 because we are a client, not a server.
//
//
