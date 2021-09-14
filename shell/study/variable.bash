# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:44 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:52 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

total=$[ $1 * $2 ]
echo The first parameter is $1.
echo The second parameter is $2.
echo The total value is $total

#如果脚本需要的命令行参数不止9个，你仍然可以处理，但是需要稍微修改一下变量名。在
#第9个变量之后，你必须在变量数字周围加上花括号，比如${10}。下面是一个这样的例子。
# handling lots of parameters
#
total=$[ ${10} * ${11} ]
echo The tenth parameter is ${10}
echo The eleventh parameter is ${11}
echo The total is $total

echo $$ #pid进程号
echo $0	#脚本文件名
echo $# #参数个数
echo $2 #第二个参数
echo $* #所有参数
echo $@	#所有参数，与$*稍有不同
echo $?	#上个命令的退出状态，或函数返回值


echo "$*" 
echo "$@"
echo $*
echo $@

echo
echo "Using the \$* method: $*"
echo
echo "Using the \$@ method: $@"

#移动变量
echo
count=1
while [ -n "$1" ]
do
echo "Parameter #$count = $1"
count=$[ $count + 1 ]
shift
done

# deal with arguments
echo
while [ -n "$1" ]
do
case "$1" in
-a) echo "Found the -a option" ;;
-b) echo "Found the -b option" ;;
-c) echo "Found the -c option" ;;
*) echo "$1 is not an option" ;;
esac
shift
done


