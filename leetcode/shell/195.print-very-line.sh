#195. 第十行
#给定一个文本文件 file.txt，请只打印这个文件中的第十行。
#
#示例:
#
#假设 file.txt 有如下内容：
#
#Line 1
#Line 2
#Line 3
#Line 4
#Line 5
#Line 6
#Line 7
#Line 8
#Line 9
#Line 10
#你的脚本应当显示第十行：
#
#Line 10

#说明:
#1. 如果文件少于十行，你应当输出什么？
#2. 至少有三种不同的解法，请尝试尽可能多的方法来解题。

# Read from the file file.txt and output the tenth line to stdout.

echo Line 1 > file.txt
echo Line 2 >> file.txt
echo Line 3 >> file.txt
echo Line 4 >> file.txt
echo Line 5 >> file.txt
echo Line 6 >> file.txt
echo Line 7 >> file.txt
echo Line 8 >> file.txt
echo Line 9 >> file.txt
echo Line 10 >> file.txt

#打印第十行
sed -n '10p' file.txt

#打印一到十行
sed -n '1,10p' file.txt

#查找指定字符
grep -n 'Line 10' file.txt

#打印指定字符上下5行
grep -C 5 'Line 10' file.txt

#打印指定字符上下N行
grep -A 100 -B 100 'Line 10' file.txt
#-A after 后面
#-B before 前面

#查找指定字符出现次数
grep -o 'Line 10' file.txt | wc -l

# 可以这么处理
grep -n "" file.txt | grep -w '10' | cut -d: -f2
sed -n '10p' file.txt
awk '{if(NR==10){print $0}}' file.txt


# 考虑到文件不足10行，可以做如下处理
row_num=$(cat file.txt | wc -l)
echo $row_num
if [ $row_num -lt 10 ];then
	echo "The number of row is less than 10"
else
    awk '{if(NR==10){print $0}}' file.txt
fi

