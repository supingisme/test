# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash
# returning an array value
# 从函数里向shell脚本传回数组变量也用类似的方法。函数用echo语句来按正确顺序输出单个
# 数组值，然后脚本再将它们重新放进一个新的数组变量中。

function arraydblr {
	local origarray
		local newarray
		local elements
		local i
		origarray=($(echo "$@"))
		newarray=($(echo "$@"))
		elements=$[ $# - 1 ]
		for (( i = 0; i <= $elements; i++ ))
		{
			newarray[$i]=$[ ${origarray[$i]} * 2 ]
		}
	echo rong: ${newarray[*]}
}
myarray=(1 2 3 4 5)
	echo "The original array is: ${myarray[*]}"
	arg1=$(echo ${myarray[*]})
	result=($(arraydblr $arg1))
	echo "The new array is: ${result[*]}"

