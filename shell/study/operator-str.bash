# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/sh

#运算符 说明                                       举例
#=   检测两个字符串是否相等，相等返回 true。      [ $a = $b ] 返回 false。
#!=  检测两个字符串是否相等，不相等返回 true。    [ $a != $b ] 返回 true。
#-z  检测字符串长度是否为0，为0返回 true。        [ -z $a ] 返回 false。
#-n  检测字符串长度是否为0，不为0返回 true。      [ -z $a ] 返回 true。
#str 检测字符串是否为空，不为空返回 true。        [ $a ] 返回 true。

a="abc"
b="efg"
if [ $a = $b ]
then
echo "$a = $b : a is equal to b"
else
echo "$a = $b: a is not equal to b"
fi
if [ $a != $b ]
then
echo "$a != $b : a is not equal to b"
else
echo "$a != $b: a is equal to b"
fi
if [ -z $a ]
then
echo "-z $a : string length is zero"
else
echo "-z $a : string length is not zero"
fi
if [ -n $a ]
then
echo "-n $a : string length is not zero"
else
echo "-n $a : string length is zero"
fi
if [ $a ]
then
echo "$a : string is not empty"
else
echo "$a : string is empty"
fi
