/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 10月 09日 星期三 08:20:26 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>
#include <stdlib.h>

typedef int INT;

#define Send_msg_to_om(module, msg, len) \
	if(0 == send_msg_to_om(module, msg, len)){\
		printf("success send %s to %s, len:%d\n",#msg, #module, len); \
	}else{ \
		printf("error send %s to %s, len:%d\n",#msg, #module, len);\
	}

enum module{
	CELL_MGMT,
	ALAR_MGMT,
	RRUS_MGMT,
};

int send_msg_to_om(enum module m, const void *msg, const int len)
{
	if(msg == NULL)
	{
		return -1;
	}
	printf("%s:%d len = %d\n", __func__, __LINE__, len);
	return 0;
}


#define do_i(i) 			\
	do{ 					\
		printf("%d", i);	

#define while_i(i) 			\
		printf("%d\n", i);	\
	}						\
	while(1);

int main()
{
#ifdef INT
	printf("int \n");
#endif

	Send_msg_to_om(CELL_MGMT, (void*)"hello", 5);
	Send_msg_to_om(ALAR_MGMT, (void*)"hello", 5);
/*	do_i(10)
	{
		
	}while_i(1);
*/
}
