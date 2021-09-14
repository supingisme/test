# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

add=`expr 2 + 2 + 123 - 999`
echo $add


a=10
b=20
val=`expr $a + $b`
echo "a + b : $val"
val=`expr $a - $b`
echo "a - b : $val"
val=`expr $a \* $b`
echo "a * b : $val"
val=`expr $b / $a`
echo "b / a : $val"
val=`expr $b % $a`
echo "b % a : $val"
if [ $a == $b ]
then
echo "a is equal to b"
fi
if [ $a != $b ]
then
echo "a is not equal to b"
fi

#运算符             说明                                          举例
#-eq 检测两个数是否相等，相等返回 true。                     [ $a -eq $b ] 返回 true。
#-ne 检测两个数是否相等，不相等返回 true。                   [ $a -ne $b ] 返回 true。
#-gt 检测左边的数是否大于右边的，如果是，则返回 true。       [ $a -gt $b ] 返回 false。
#-lt 检测左边的数是否小于右边的，如果是，则返回 true。       [ $a -lt $b ] 返回 true。
#-ge 检测左边的数是否大等于右边的，如果是，则返回 true。     [ $a -ge $b ] 返回 false。
#-le 检测左边的数是否小于等于右边的，如果是，则返回 true。   [ $a -le $b ] 返回 true。


#!   非运算，表达式为 true 则返回 false，否则返回 true。 [ ! false ] 返回 true。
#-o  或运算，有一个表达式为 true 则返回 true。 [ $a -lt 20 -o $b -gt 100 ] 返回 true。
#-a  与运算，两个表达式都为 true 才返回 true。 [ $a -lt 20 -a $b -gt 100 ] 返回 false

if [ $a -eq $b ]
then
echo "$a -eq $b : a is equal to b"
else
echo "$a -eq $b: a is not equal to b"
fi
if [ $a -ne $b ]
then
echo "$a -ne $b: a is not equal to b"
else
echo "$a -ne $b : a is equal to b"
fi
if [ $a -gt $b ]
then
echo "$a -gt $b: a is greater than b"
else
echo "$a -gt $b: a is not greater than b"
fi
if [ $a -lt $b ]
then
echo "$a -lt $b: a is less than b"
else
echo "$a -lt $b: a is not less than b"
fi
if [ $a -ge $b ]
then
echo "$a -ge $b: a is greater or equal to b"
else
echo "$a -ge $b: a is not greater or equal to b"
fi
if [ $a -le $b ]
then
echo "$a -le $b: a is less or equal to b"
else
echo "$a -le $b: a is not less or equal to b"
fi


if [ $a != $b ]
then
echo "$a != $b : a is not equal to b"
else
echo "$a != $b: a is equal to b"
fi
if [ $a -lt 100 -a $b -gt 15 ]
then
echo "$a -lt 100 -a $b -gt 15 : returns true"
else
echo "$a -lt 100 -a $b -gt 15 : returns false"
fi
if [ $a -lt 100 -o $b -gt 100 ]
then
echo "$a -lt 100 -o $b -gt 100 : returns true"
else
echo "$a -lt 100 -o $b -gt 100 : returns false"
fi
if [ $a -lt 5 -o $b -gt 100 ]
then
echo "$a -lt 100 -o $b -gt 100 : returns true"
else
echo "$a -lt 100 -o $b -gt 100 : returns false"
fi


# 双括号命令符号
#
# val++ 后增
# val-- 后减
# ++val 先增
# --val 先减
# ! 逻辑求反
# ~ 位求反
# ** 幂运算
# << 左位移
# >> 右位移
# & 位布尔和
# | 位布尔或
# && 逻辑和
# || 逻辑或


# using double parenthesis
#
val1=10
#
if (( $val1 ** 2 > 90 ))
then
(( val2 = $val1 ** 2 ))
echo "The square of $val1 is $val2"
fi


#使用双方括号
#
# 双方括号命令提供了针对字符串比较的高级特性。双方括号命令的格式如下：
# [[ expression ]]
# 双方括号里的expression使用了test命令中采用的标准字符串比较。但它提供了test命
# 令未提供的另一个特性——模式匹配（pattern matching）。
# 在模式匹配中，可以定义一个正则表达式（将在第20章中详细讨论）来匹配字符串值。
# using pattern matching
#
if [[ $USER == r* ]]
then
echo "Hello $USER"
else
echo "Sorry, I do not know you"
fi