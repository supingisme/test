# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash
# using recursion
function factorial {
	if [ $1 -eq 1 ]
	then
		echo 1
	else
		local temp=$[ $1 - 1 ]
		local result=$(factorial $temp)
		echo $[ $result * $1 ]
	fi
}
read -p "Enter value: " value
result=$(factorial $value)
echo "The factorial of $value is: $result"
