# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

# ARG1 | ARG2 如果ARG1既不是null也不是零值，返回ARG1；否则返回ARG2
# ARG1 & ARG2 如果没有参数是null或零值，返回ARG1；否则返回0
# ARG1 < ARG2 如果ARG1小于ARG2，返回1；否则返回0
# ARG1 <= ARG2 如果ARG1小于或等于ARG2，返回1；否则返回0
# ARG1 = ARG2 如果ARG1等于ARG2，返回1；否则返回0
# ARG1 != ARG2 如果ARG1不等于ARG2，返回1；否则返回0
# ARG1 >= ARG2 如果ARG1大于或等于ARG2，返回1；否则返回0
# ARG1 > ARG2 如果ARG1大于ARG2，返回1；否则返回0
# ARG1 + ARG2 返回ARG1和ARG2的算术运算和
# ARG1 - ARG2 返回ARG1和ARG2的算术运算差
# ARG1 * ARG2 返回ARG1和ARG2的算术乘积
# ARG1 / ARG2 返回ARG1被ARG2除的算术商
# ARG1 % ARG2 返回ARG1被ARG2除的算术余数
# STRING : REGEXP 如果REGEXP匹配到了STRING中的某个模式，返回该模式匹配
# match STRING REGEXP 如果REGEXP匹配到了STRING中的某个模式，返回该模式匹配
# substr STRING POS LENGTH 返回起始位置为POS（从1开始计数）、长度为LENGTH个字符的子字符串
# index STRING CHARS 返回在STRING中找到CHARS字符串的位置；否则，返回0
# length STRING 返回字符串STRING的数值长度
# + TOKEN 将TOKEN解释成字符串，即使是个关键字
# (EXPRESSION) 返回EXPRESSION的值


echo $[1 + 3]
expr 1 + 3


val=`expr 2 + 2`
echo "Total value : $val"
#两点注意： 
#- 表达式和运算符之间要有空格，例如 2+2 是不对的，必须写成 2 + 2，这与我们熟悉的大多数编程语言不一样。 
#- 完整的表达式要被包含，注意这个字符不是常用的单引号，在 Esc 键下边。

