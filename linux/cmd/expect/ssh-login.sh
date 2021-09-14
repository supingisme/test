#!/bin/bash

# bash name
#运行方式： bash name.sh ; sh name.sh; ./name.sh

passwd='rong '

/usr/bin/expect <<-EOF

set time 5
spawn ssh rongtao@10.170.6.66 df -Th
expect {
	"*yes/no" { send "yes\r"; exp_continue }
	"*password:" { send "$passwd\r" }
}
expect eof

EOF


