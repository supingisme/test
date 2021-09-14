# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:24 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:49 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:19 CST. 
#!/bin/bash
# Extract command line options & values with getopt
#
set -- $(getopt -q ab:cd "$@")
#
echo
while [ -n "$1" ]
do
case "$1" in
-a) echo "Found the -a option" ;;
-b) param="$2"
echo "Found the -b option, with parameter value $param"
shift ;;
-c) echo "Found the -c option" ;;
--) shift
break ;;
*) echo "$1 is not an option";;
esac
shift
done
#
count=1
for param in "$@"
do
echo "Parameter #$count: $param"
count=$[ $count + 1 ]
done
# constant to used
#-a 显示所有对象
#-c 生成一个计数
#-d 指定一个目录
#-e 扩展一个对象
#-f 指定读入数据的文件
#-h 显示命令的帮助信息
#-i 忽略文本大小写
#-l 产生输出的长格式版本
#-n 使用非交互模式（批处理）
#-o 将所有输出重定向到的指定的输出文件
#-q 以安静模式运行
#-r 递归地处理目录和文件
#-s 以安静模式运行
#-v 生成详细输出
#-x 排除某个对象
#-y 对所有问题回答yes
