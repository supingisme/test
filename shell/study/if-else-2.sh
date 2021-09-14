# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

# if-then语句允许你使用布尔逻辑来组合测试。有两种布尔运算符可用：
#  [ condition1 ] && [ condition2 ]
#  [ condition1 ] || [ condition2 ]
# 第一种布尔运算使用AND布尔运算符来组合两个条件。要让then部分的命令执行，两个条件
# 都必须满足。

# testing compound comparisons
#
if [ -d $HOME ] && [ -w $HOME/test ]
then
echo "The file exists and you can write to it"
else
echo "I cannot write to the file"
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
