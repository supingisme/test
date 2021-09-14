/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 21日 星期四 09:04:25 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 09:35:20 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 09:35:15 CST. */


struct mq_attr {
	long mq_flags;       /* Flags: 0 or O_NONBLOCK */
	long mq_maxmsg;      /* Max. # of messages on queue */
	long mq_msgsize;     /* Max. message size (bytes) */
	long mq_curmsgs;     /* # of messages currently in queue */
};

struct mq_attr{
	long mq_flags; /* message queue flag: 0, 0-NONBLOCK */
	long mq_maxmsg; /* max number of messages allowed on queue */
	long mq_msgsize; /* max size of a message (in bytes) */
	long mq_curmsgs; /* number of messages currently on queue */
};
