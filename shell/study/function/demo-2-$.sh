# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash
# testing the exit status of a function
func1() {
	echo "trying to display a non-existent file"
		ls -l badfile
}
echo "testing the function: "
func1
echo "The exit status is: $?"

#默认情况下，函数的退出状态码是函数中最后一条命令返回的退出状态码。在函数执行结束
#后，可以用标准变量$?来确定函数的退出状态码。


#use return commond

#!/bin/bash
# using the return command in a function
function dbl {
	read -p "Enter a value: " value
		echo "doubling the value"
		return $[ $value * 2 ]
}
dbl
echo "The new value is $?"


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

