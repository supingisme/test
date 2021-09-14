# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:24 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:49 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:19 CST. 
#!/bin/bash

# seperate operator
echo "rong:tao hello "|awk -F':' '{print $2}'

#4. 在程序脚本中使用多个命令
#如果一种编程语言只能执行一条命令，那么它不会有太大用处。 gawk编程语言允许你将多条
#命令组合成一个正常的程序。要在命令行上的程序脚本中使用多条命令，只要在命令之间放个分
#号即可。
echo "My name is Rongtao" | awk '{$4="rongtao"; print $0}'


#从文件中读取指令
echo "rong tao" | awk -f script.awk 


#在处理数据前运行脚本
echo "rong tao" | awk 'ls{print "The sh"}{print $2}'


#在处理数据后运行脚本
echo "----------------"
echo "rong1 tao1" | awk 'BEGIN{print "rong2 tao2"}{print $2}END{print "END"}'
