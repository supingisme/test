#!/bin/bash 


function  invoke_trap() {
	echo call trap
}

# 脚本退出时会调用 函数 invoke_trap 
# 类似于 signal(SIGINT, invoke_trap)
trap "invoke_trap" 0

while :;
do
	echo sleep
	sleep 1
done

