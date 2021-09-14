#!/bin/bash 

ip=$1  
user=$2 
password=$3 

expect << EOF  

	set timeout 10 
	spawn ssh $user@$ip 
	expect { 
		"yes/no" { send "yes\n"; exp_continue } 
		"password" { send "$password\n" }
	} 
    expect "]#" { send "useradd test\n" } 
	expect "]#" { send "touch /tmp/test.txt\n" } 
	expect "]#" { send "exit\n" } expect eof 
EOF  
#./ssh5.sh 192.168.1.10 root 123456
