# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:44 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:52 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

#until命令和while命令工作的方式完全相反。 until命令要求你指定一个通常返回非零退
#出状态码的测试命令。只有测试命令的退出状态码不为0， bash shell才会执行循环中列出的命令。
#一旦测试命令返回了退出状态码0，循环就结束了。


a=0
until [ ! $a -lt 10 ] #如果返回值为 false，则继续执行循环体内的语句，否则跳出循环。
do
echo $a
a=`expr $a + 1`
done
