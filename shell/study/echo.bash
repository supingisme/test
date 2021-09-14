# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 


echo "rong\ntao\n"
echo -e "rong\ntao\n"

echo -e "\033[1;31;42mRongTao\033[m"

#-E	禁止转义

#\a 报警
#\b 退格
#\f 换页
#\n	换行
#\r	回车
#\t	制表符
#\v	垂直制表符

echo -e "rong tao\"s good"

mouth=8
echo "${mouth}-1-2009"

echo -e "OK!\n"
echo "It is a test"

echo -e "OK!\c"
echo "It is a test"

echo "It is a test" > myfile

name="RongTao"
echo -e "$name\""
echo -e '$name\"'