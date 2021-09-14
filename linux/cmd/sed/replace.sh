#!/bin/bash

function replace_file()
{
#echo ">>$*"
	if [ -d $1 ]; then
		cd $1
		files=`ls`
#echo $files
		for file in $files
		do
#echo "_sed_file_ $file $2 $3"
			replace_file $file $2 $3
		done
		cd ..
	else
#echo '$2/$3' $1
		sed -i "s/$2/$3/g" $1
		echo "sed -i "s/$2/$3/g" $PWD/$1"
#echo " ret = $?"
	fi
}

if [ $# -lt 3 ]; then
	echo "Usage: $0 [file/path] [string-before] [string-after]"
	exit
fi
replace_file $*

