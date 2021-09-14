/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:43 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:17 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:27 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:11 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>


void str_cli(FILE *fp, int sockfd)
{
	int maxfdp1;
	fd_set rset;
	
	FD_ZERO(&rset);
	for(;;)
	{
		FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);

		maxfdp1 = fileno(fp)>sockfd?fileno(fp):sockfd;

		select(maxfdp1, &rset, NULL, NULL, NULL);

		if(FD_ISSET(sockfd, &rset))
		{
			write(sockfd, "sockfd ready\n");
		}
		if(FD_ISSET(fileno(fp), &rset))
		{
			fprintf(fp, "fp ready\n");
		}
		sleep(1);
	}
}	

int main()
{
	while(1)
	{
		str_cli(stdout, fileno(stderr));

		fprintf(stdout, "stdout \n");
		fprintf(stderr, "stderr \n");

		sleep(1);
	}

	return 0;
}
