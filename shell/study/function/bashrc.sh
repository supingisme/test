# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
# .bashrc
# 直接定义函数
# Source global definitions
if [ -r /etc/bashrc ]; then
. /etc/bashrc
fi
function addem {
	echo $[ $1 + $2 ]
}

# 读取函数文件
# .bashrc
# Source global definitions
if [ -r /etc/bashrc ]; then
	. /etc/bashrc
fi
. ./library.sh
