# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. 


Usage:

$ ./create.out 
usage: ./create.out [ -e ] <name> <length>
[rongtao@localhost demon-shm]$ ./create.out myshm 6
fd = 3, length = 6, flags = 0x42, name = myshm
ftruncate return: 0
[rongtao@localhost demon-shm]$ ./write.out myshm
fd = 3
stat.st_size = 6
[rongtao@localhost demon-shm]$ ./read.out myshm
fd = 3
stat.st_size = 6
ptr = 0
ptr = 1
ptr = 2
ptr = 3
ptr = 4
ptr = 5
[rongtao@localhost demon-shm]$ ./unlink.out myshm
ret = 0
[rongtao@localhost demon-shm]$ ./unlink.out myshm
ret = -1
[rongtao@localhost demon-shm]$ 
