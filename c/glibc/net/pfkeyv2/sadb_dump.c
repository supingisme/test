/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:16 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
#include "unp.h"
#include <net/pfkeyv2.h>

/* include sadb_dump */
void
sadb_dump(int type)
{
	int s;
	char buf[4096];
	struct sadb_msg msg;
	int goteof;

	s = Socket(PF_KEY, SOCK_RAW, PF_KEY_V2);

	/* Build and write SADB_DUMP request */
	bzero(&msg, sizeof(msg));
	msg.sadb_msg_version = PF_KEY_V2;
	msg.sadb_msg_type = SADB_DUMP;
	msg.sadb_msg_satype = type;
	msg.sadb_msg_len = sizeof(msg) / 8;
	msg.sadb_msg_pid = getpid();
	printf("Sending dump message:\n");
	print_sadb_msg(&msg, sizeof(msg));
	Write(s, &msg, sizeof(msg));

	printf("\nMessages returned:\n");
	/* Read and print SADB_DUMP replies until done */
	goteof = 0;
	while (goteof == 0) {
		int msglen;
		struct sadb_msg *msgp;

		msglen = Read(s, &buf, sizeof(buf));
		msgp = (struct sadb_msg *)&buf;
		print_sadb_msg(msgp, msglen);
		if (msgp->sadb_msg_seq == 0)
			goteof = 1;
	}
	close(s);
}

int
main(int argc, char **argv)
{
	int satype = SADB_SATYPE_UNSPEC;
	int c;

	opterr = 0;		/* don't want getopt() writing to stderr */
	while ( (c = getopt(argc, argv, "t:")) != -1) {
		switch (c) {
		case 't':
			if ((satype = getsatypebyname(optarg)) == -1)
				err_quit("invalid -t option %s", optarg);
			break;

		default:
			err_quit("unrecognized option: %c", c);
		}
	}

	sadb_dump(satype);
}
/* end sadb_dump */
