# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
for name in ada ron tao java cpp
do
	echo ${name}
done


for loop in 1 2 3 4 5
do
echo "The value is: $loop"
done

for FILE in $HOME/.bash*
do
echo $FILE
done


for ((i=0; i<10; i++))
do 
echo $i
done


for (( a=1, b=10; a <= 10; a++, b-- ))
do
echo "$a - $b"
done
