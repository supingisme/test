# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
# my script functions
function addem {
	echo $[ $1 + $2 ]
}
function multem {
	echo $[ $1 * $2 ]
}
function divem {
	if [ $2 -ne 0 ]
	then
		echo $[ $1 / $2 ]
	else
		echo -1
	fi
}


