# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

array_name[0]=value0
array_name[1]=value1
array_name[2]=value2

array_name=(
value0
value1
value2
value3
)

echo ${array_name[1]}


NAME[0]="Zara"
NAME[1]="Qadir"
NAME[2]="Mahnaz"
NAME[3]="Ayan"
NAME[4]="Daisy"
echo "First Index: ${NAME[0]}"
echo "Second Index: ${NAME[1]}"
echo "First Method: ${NAME[*]}"
echo "Second Method: ${NAME[@]}"

length=${#array_name[@]}
echo $length
length=${#array_name[*]}
echo $length
# 取得数组单个元素的长度
lengthn=${#array_name[1]}
echo $lengthn
