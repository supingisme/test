#!/bin/bash 
# 2021.11.02 Rong Tao

usage() {
cat<<'EOF'
	Usage: exe [text file] [splite line]
EOF
}

if [ $# -lt 2 ]; then
	usage
	exit 1 
fi


local count=0
local lines=0
file=$1
splice_count=$2

for i in `cat $file | sed 's/\ //g'`
do  
	count=`expr $count + 1` 
	echo -e "| $i \c"
	if [ $count = $splice_count ]; then
		echo -e "|"
		count=0
		lines=`expr $lines + 1`

		if [ $lines = 1 ]; then
			for ((i=0; i<$splice_count; i++ ))
			do
				#echo ">>> $i"
				echo -e "| - \c"
			done
			echo "|"
		fi
	fi
done

echo ""
echo "Total $lines line."
