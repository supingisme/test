# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:55 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:58 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:27 CST. 
#!/bin/bash

if [ $# -lt 1 ]; then
	echo usage: $0 [file.c]
	exit
fi

gcc $1 `pkg-config --libs --cflags x11 xmu`
