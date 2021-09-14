# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
#This function to kill/clean jt_sran/om's process
#	Rong Tao: 2019
function jt_clean 
{
pidfile=`mktemp tmpXXX.out`

if [ $# -gt 0 ]; then
files=( $* )
else
files=("ue_simu_phy" "lteue" "simu_mac" "snmpd" "jt_sran" "simu_phy" "simu_rru" "l1app" "l2l3app")
fi
#function clean_cells_folder
#{
#rm -rf /etc/jt_product/jt_sran/L2_L3/cells/*
#}

#clean_cells_folder
#rm -rf /etc/jt_product/jt_sran/L2_L3/cells/*

#files=("ue_simu_phy" "lteue" "simu_mac" "snmpd" "jt_sran" "simu_phy" "simu_rru" "l1app" "l2l3app")

for file in ${files[*]}
do
	echo -e ">> Ready to kill \033[1;31m$file\033[0m pid"
	ps -e | grep $file | awk '{print $1}' | tee >>$pidfile
done

pids=`cat $pidfile`

if [ -r $pidfile ]; then
	#file is not empty
	if [ -s $pidfile ]; then
		for pid in $pids
		do
			#if pid is not zero
			if [ -n "$pid" ]; then
				kill $pid
			fi
		done
		echo "Success."
	else
		echo "No pid exist."
	fi
fi

rm -f $pidfile
}

jt_clean a.out
