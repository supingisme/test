#!/bin/bash

function generate_ld_verbose_file()
{
	if [ $# -lt 1 ]; then
		echo "Usage: $0 [ld file name]"
		return 1
	fi
	
	ldfile=$1

	ld --verbose > $ldfile

	#删除最后一行
	sed -i '$d' $ldfile

	#行翻转
	tmpfile=`mktemp`
	findstring="========="

	tac $ldfile > $tmpfile
	findline=`grep $findstring $tmpfile`
	endline=`sed -n '$p' $tmpfile`

	until [[ $findline = $endline ]]
	do
		#echo "$findline VS $endline"
		#删除最后一行
		sed -i '$d' $tmpfile
		endline=`sed -n '$p' $tmpfile`
	done

	#删除最后一行
	sed -i '$d' $tmpfile

	tac $tmpfile > $ldfile

	#删除临时文件
	rm -rf $tmpfile
	
	return 0
}

generate_ld_verbose_file $1


function add_my_init_section_to_ld_verbose_file()
{
	if [ $# -lt 2 ]; then
		echo "Usage: $0 [ld file name] [my init section name]"
		return 1
	fi

	ldverbosefile=$1
	myinitsectionfile=$2

	string="__bss_start"

	line=`grep $string $ldverbosefile`
	num=$(grep -n "$line" $ldverbosefile | awk -F ':' '{print $1}')

	num=$(expr $num - 1)

	numa=$num" r"

	sed -i "$numa $myinitsectionfile" $ldverbosefile
	
	return 0
}

add_my_init_section_to_ld_verbose_file $1 $2





