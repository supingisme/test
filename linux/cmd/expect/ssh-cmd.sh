#!/usr/bin/expect

#运行方式
# expect name.sh;
# ./name.sh

spawn ssh rongtao@10.170.6.66 df -Th
expect "*password"
send "rong \n"
expect eof


