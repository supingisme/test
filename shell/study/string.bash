# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
your_name='qinjx'
str="Hello, I know your are \"$your_name\"! \n"

echo -e $str + $your_name

greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"
echo $greeting $greeting_1

string="abcd"
echo ${#string} #输出4

string="alibaba is a great company"
echo ${string:1:4} #输出 liba
echo `expr index "$string" is` #查找子字符串


echo "=====$1 M"

function aaa
{
	echo "$1 $2m"
}

aaa 123 adsfadsf

#str1 = str2 检查str1是否和str2相同
#str1 != str2 检查str1是否和str2不同
#str1 < str2 检查str1是否比str2小
#str1 > str2 检查str1是否比str2大
#-n str1 检查str1的长度是否非0
#-z str1 检查str1的长度是否为0
