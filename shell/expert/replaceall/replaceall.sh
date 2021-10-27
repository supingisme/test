#!/bin/bash 

this_file=$(basename $0)

usage() {

cat<<'EOF'
	Usage:
	CMD  [from] [to]	
EOF
	exit 1
}

rename_file() {
	local from=$2
	local to=$3
	local toname=`basename $1 | sed "s/$from/$to/g"`
	echo "Toname $toname | grep $from"
	echo `basename $1` | grep $from 2>&1 >/dev/null  
	if [ $? = 0 ]; then
		local path=`dirname $1`
		echo "mv $1 $path/$toname"
		mv $1 $path/$toname
	fi
}

replace_words() {
	if [ $# -lt 3 ]; then
		usage
	fi
	from=$2
	to=$3
	if [ -d $1 ]; then
		#echo ">>> cd $1"
		cd $1
		for file in `ls $1`
		do
			replace_words $1/$file $from $to
		done
		rename_file $1 $from $to
		cd -
	else
		echo "sed -i \"s/$from/$to/g\" $1"
		sed -i "s/$from/$to/g" $1
		rename_file $1 $from $to
	fi
}

if [ $# -lt 2 ]; then
	usage
fi

for file in `ls`
do
	replace_words $PWD/$file $1 $2

done
