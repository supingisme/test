/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 08:57:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */

/* This library function assists the user with the advanced features
 * of SCTP.  This is a new SCTP API described in the section 8.8 of the
 * Sockets API Extensions for SCTP. This is implemented using the
 * recvmsg() interface.
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>

//Receive a message from a SCTP socket.
int sctp_recvmsg(int sd, void * msg, size_t len,
                struct sockaddr * from, socklen_t * fromlen,
                struct sctp_sndrcvinfo * sinfo, int * msg_flags);



int Sctp_recvmsg(int s, void *msg, size_t len,
			     struct sockaddr *from, socklen_t *fromlen,
			     struct sctp_sndrcvinfo *sinfo,
			     int *msg_flags)
{
	int ret;
	ret = sctp_recvmsg(s,msg,len,from,fromlen,sinfo,msg_flags);
	if(ret < 0){
		err_sys("sctp_recvmsg error");
	}
	return(ret);
}
