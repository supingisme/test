#!/bin/bash
export LD_LIBRARY_PATH=/usr/local/lib:./lib
file_num=100000
file_size=10000
if [ $# != 1 ]
then
	echo "param error"
else
	while getopts "xenascw" arg
	do
		case $arg in
			x)
				./aioperf -x
				;;
			e)
				./aioperf -e
				;;
			n)      
				./aioperf -n
				;;
			a)     
				 ./aioperf -a
				;;
			s)     
				 ./aioperf -s
				;;
			w)  
				rm -rf ./test_data/test_write
				mkdir -p ./test_data/test_write
				;;
			c)
				rm -rf ./test_data/test_read
				rm -rf ./test_data/test_write
				mkdir -p ./test_data/test_read/
				mkdir -p ./test_data/test_write/
				
				cd ./test_data/test_read/
				dd if=/dev/zero of=data count=1 bs=$file_size
				echo "create read test data files,please wait....."
				for (( count=0; count<$file_num; count++ ));
				do
					nf=000000$count
					nf=${nf:0-6:6}
					#dd if=/dev/zero of=$nf count=1 bs=10K
					cp data $nf
				done
				rm -f data
				echo "create done!"
				;;
		esac
	done
fi
