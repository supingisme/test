# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash
# passing parameters to a function
function addem {
	if [ $# -eq 0 ] || [ $# -gt 2 ]
		then
			echo -1
			elif [ $# -eq 1 ]
			then
			echo $[ $1 + $1 ]
	else
		echo $[ $1 + $2 ]
			fi
}
echo -n "Adding 10 and 15: "
value=$(addem 10 15)
	echo $value
	echo -n "Let's try adding just one number: "
	value=$(addem 10)
	echo $value
	echo -n "Now trying adding no numbers: "
	value=$(addem)
	echo $value
	echo -n "Finally, try adding three numbers: "
	value=$(addem 10 15 20)
	echo $value
