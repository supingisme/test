#!/bin/bash
# 获取网卡信息

function getallifnames() {
	ethifnames=$(ifconfig -s | sed -e "1d" | awk '{print $1}')
	echo $ethifnames
	return 0
}

function getifspeedbyname() {
	if [ $# -lt 1 ]; then 
		echo "NULL"
		return 1
	fi
	ifname=$1
#	echo "ready to get: $ifname"
	speed=`ethtool $ifname | grep Speed | awk '{print $2}'`
	if [ -z $speed ];then 
		echo "Unknown!"
	else
		echo $speed
	fi
	return 0
}

function getifstatbyname() {
	if [ $# -lt 1 ]; then
                echo "NULL"
                return 1
        fi
	ifname=$1
	ifconfig $ifname | grep RUNNING > /dev/null
	
	if [ $? -eq 0 ]; then
		echo "up"	
	else
		echo "down"
	fi
}

ifnames=`getallifnames`

echo -e "\033[1m\tName \tSpeed  \tStatus  \033[m"
for ifname in $ifnames
do 
	speed=$(getifspeedbyname $ifname)
	status=$(getifstatbyname $ifname)
	echo -e "\t$ifname \t$speed \t$status"
done
