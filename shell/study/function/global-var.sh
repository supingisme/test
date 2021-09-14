# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash
# using a global variable to pass a value
function dbl {
value=$[ $value * 2 ]
}
read -p "Enter a value: " value
dbl
echo "The new value is: $value"



# demonstrating a bad use of variables
function func1 {
	temp=$[ $value + 5 ]
		result=$[ $temp * 2 ]
}
temp=4
value=6
func1
echo "The result is $result"
if [ $temp -gt $value ]
then
echo "temp is larger"
else
echo "temp is smaller"
fi



