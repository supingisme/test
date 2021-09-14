#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "mq.h"

int main()
{
	int flags = O_RDWR|O_CREAT|O_EXCL;
	
	mqd_t	mqd;
	struct mq_attr attr;

	attr.mq_maxmsg = 256;
	attr.mq_msgsize = 1024;

	mqd = mq_open(_MQ_NAME, flags, FILE_MODE, &attr);
	//if(!mqd)
		perror("mq_open:");

	mq_close(mqd);

	return 0;
}
