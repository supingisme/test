/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 06月 20日 星期四 08:25:12 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 20日 星期四 08:25:06 CST. */

#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>
#include <errno.h>
#include <string.h>

void abortfun(enum mcheck_status mstatus)
{
	fprintf(stderr, "abortfun called with %d\n", mstatus);
    switch(mstatus){
        case MCHECK_DISABLED:
            printf("consistency checking is not turned on\n");
            break;
        case MCHECK_OK:
            printf("block is fine\n");
            break;
        case MCHECK_FREE:
            printf("block freed twice\n");
            break;
        case MCHECK_HEAD:
            printf("memory before the block was clobbered\n");
            break;
        case MCHECK_TAIL:
            printf("memory after the block was clobbered\n");
            break;
    }
}

int main(int argc, char *argv[])
{
	char *p = NULL;

	if(mcheck(abortfun) != 0)
	{
		fprintf(stderr, "mcheck:%s\n", strerror(errno));
		return -1;
	}
	p = malloc(10);
	free(p);
	printf("1st free finished.\n");
//	free(p);
//	printf("2nd free.\n");

	return 0;
}
