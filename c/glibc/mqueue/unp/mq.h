#ifndef __MY_MQUEUE_H
#define __MY_MQUEUE_H 1

#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>

#define _MQ_NAME	"/_test_mq"

#define	FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)


#endif //__MY_MQUEUE_H
