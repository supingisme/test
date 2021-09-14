#!/usr/bin/expect -f

set timeout 10

spawn sudo su - root
expect "*password*"
send "root \r\n"
expect "*#"
send "ls\r\n"
expect "*#"
send "df -Th\r\n"
expect "*#"
send "exit\r\n"

expect eof


