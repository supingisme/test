# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash
DATE=`date`
echo "Date is $DATE"
USERS=`who | wc -l`
echo "Logged in user are $USERS"
UP=`date ; uptime`
echo "Uptime is $UP"

LS=`ls`
echo ${LS:-"folder ls is: "}

echo -e "\n"

#形式                      说明
#${var}              变量本来的值
#${var:-word}        如果变量 var 为空或已被删除(unset)，
#                    那么返回 word，但不改变 var 的值
#${var:=word}        如果变量 var 为空或已被删除(unset)，
#                    那么返回 word，并将 var 的值设置为 word。
#${var:?message}     如果变量 var 为空或已被删除(unset)，
#                    那么将消息 message 送到标 准错误输出，
#                    可以用来检测变量 var 是否可以被正常赋值。
#                    若此替换出现在 Shell 脚本中，那么脚本将停止运行。
#${var:+word}        如果变量 var 被定义，那么返回 word，但不改变 var 的值。

echo ${var:-"Variable is not set"}
echo "1 - Value of var is ${var}"
echo ${var:="Variable is not set"}
echo "2 - Value of var is ${var}"
unset var
echo ${var:+"This is default value"}
echo "3 - Value of var is $var"
var="Prefix"
echo ${var:+"This is default value"}
echo "4 - Value of var is $var"
echo ${var:?"Print this message"}
echo "5 - Value of var is ${var}"