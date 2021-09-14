# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 

#如果希望执行某个命令，但又不希望在屏幕上显示输出结果，那么可以将输出重定向到 /dev/null：
#$ command > /dev/null
#/dev/null #是一个特殊的文件，写入到它的内容都会被丢弃；如果尝试从该文件读取内容，那么什么也读不到。
#但是 /dev/null 文件非常有用，将命令的输出重定向到它，会起到”禁止输出“的效果。
#如果希望屏蔽 stdout 和 stderr，可以这样写：
#$ command > /dev/null 2>&1文件

cat tmp.bash > /dev/null 2>&1 
