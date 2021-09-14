# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash
# trying to pass an array variable
function testit {
	echo "The parameters are: $@"
		thisarray=$1
		echo "The received array is ${thisarray[*]}"
}
myarray=(1 2 3 4 5)
	echo "The original array is: ${myarray[*]}"
	testit $myarray

#如果你试图将该数组变量作为函数参数，函数只会取数组变量的第一个值。
#要解决这个问题，你必须将该数组变量的值分解成单个的值，然后将这些值作为函数参数使
#用。在函数内部，可以将所有的参数重新组合成一个新的变量。下面是个具体的例子。


# array variable to function test
function testit1 {
	local newarray1
	newarray1=(`echo "$@"`)
	echo "The new array value is: ${newarray1[*]}"
}
myarray1=(1 2 3 4 5)
echo "The original array is ${myarray1[*]}"
testit1 ${myarray1[*]}


#该脚本用$myarray变量来保存所有的数组元素，然后将它们都放在函数的命令行上。该函
#数随后从命令行参数中重建数组变量。在函数内部，数组仍然可以像其他数组一样使用。
#!/bin/bash
# adding values in an array
function addarray {
	local sum=0
	local newarray
	newarray=($(echo "$@"))
	for value in ${newarray[*]}
	do
		sum=$[ $sum + $value ]
	done
	echo $sum
}
myarray=(1 2 3 4 5)
echo "The original array is: ${myarray[*]}"
arg1=$(echo ${myarray[*]})
result=$(addarray $arg1)
echo "The result is $result"
