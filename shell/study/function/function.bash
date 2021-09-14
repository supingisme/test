# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash

function func1 {
    echo "hello world!"
}

function func2 {
    echo "hello world! $1 $# $@"
}

function func3 {
    return 12
}

#return range 0~255
function func4 {
    return 255
}

function func5 {
    echo "[`date '+%F %T'`]:$@"
}

function func6 {
    find . -name $1
}

function func7 {
    clear
    while(true)
    do
        date +'%T'
        sleep 1
        clear
    done
}

function_name1 () {
    echo $$
    echo $@
    echo $*
    echo $1
    return 0
}
function function_name2 () {
    echo $$
    return 0
}

func1
func2 RongTao sylincom
func3
echo "$?"
func4
echo "$?"
func5 RongTao
func6 d1
#func7
function_name1 12
function_name2 12