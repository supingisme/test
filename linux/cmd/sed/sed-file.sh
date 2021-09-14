# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:25 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:49 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:20 CST. 
#!/bin/bash

# 写入文件
echo "-------------写入文件----------------"
sed '1,2w test.out' data1.txt
echo "-------------------------------------"
cat test.out
rm test.out

echo "-------------------------------------"
sed -n '/number/w test.txt' data1.txt
cat test.txt
rm test.txt


# 从文件读取数据
echo "------------------从文件读取数据------------------"
sed '3r data2.txt' data1.txt

echo "--------------------------------------------------"
sed '/number/r data2.txt' data1.txt
echo "--------------------------------------------------"
echo "为啥错了？？？？？？？？？？？？？？？？？？？？？"
sed '/LIST/{ r data3.txt ; d }' notice.txt
sed '/LIST/r data3.txt' notice.txt







