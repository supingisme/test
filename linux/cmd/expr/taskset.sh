#!/bin/bash

if [ $# -lt 2 ]; then
	echo "$0 [number-like-string] [exe]"
	exit 1
fi

string=$1

string_num=`echo $string | tr -cd [0-9]`
cpu_core_num=`grep 'core id' /proc/cpuinfo |wc -l`

echo 原始字符串	$string
echo 提取数字	$string_num
echo 总核心数	$cpu_core_num

core_taskset=`expr $string_num % $cpu_core_num `

echo 绑核至		$core_taskset

taskset -c $core_taskset $2
