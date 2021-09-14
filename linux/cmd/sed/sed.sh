# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:25 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:49 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:20 CST. 
#!/bin/bash

#g替换标记使你能替换文本中匹配模式所匹配的每处地方。
echo "rongtao rong at Sylincom" | sed 's/rong/trial/g'

#p替换标记会打印与替换命令中指定的模式匹配的行。
echo "rongtao rong at Sylincom" | sed 's/rong/trial/p'

#-n选项将禁止sed编辑器输出,但p替换标记会输出修改过的行
echo "rongtao rong at Sylincom" | sed -n 's/rong/trial/p'

#替换字符
sed 's/\/bin\/bash/\/bin\/csh/' /etc/passwd

#sed编辑器允许选择其他字符来作为替换命令中的字符串分隔符：
sed 's!/bin/bash!/bin/csh!' /etc/passwd
echo "/home/rongta" | sed 's!/home!/rong/!g' 

#使用地址
#数字方式的行寻址
#data1.txt
#The quick brown fox jumps over the lazy dog
#The quick brown fox jumps over the lazy dog
#The quick brown fox jumps over the lazy dog
#The quick brown fox jumps over the lazy dog
sed '2s/dog/cat/' data1.txt
echo "----------------------"
sed '2,3s/dog/cat/' data1.txt
echo "----------------------"
sed '2,$s/dog/cat/' data1.txt


#使用文本模式过滤器
#只修改用户Samantha的默认shell
sed -n '/rongtao/s/bash/csh/p' /etc/passwd


#命令组合
sed '2{
	s/dog/cat/
	s/lazy/pretty/
}' data1.txt

sed '2,${
	s/dog/cat/
	s/lazy/pretty/
}' data1.txt


#删除行
echo "delete line ---------------"
sed 'a' data1.txt

echo "delete 3rd line"
sed '3d' data1.txt

echo "delete 2ed and 3rd lines"
sed '2,3d' data1.txt

echo "delete 3ed to final lines"
sed '3,$d' data1.txt

echo 'module catch delete'
sed '/dog/d' data1.txt

# sed编辑器会删除两个指定行之间的所有行
echo "----------------sed '/number 1/,/number 3/d' data1.txt"
sed '/number 1/,/number 3/d' data1.txt



#插入和附加文本#####################################
#插入（insert）命令（i）会在指定行前增加一个新行；
#附加（append）命令（a）会在指定行后增加一个新行。
echo "-----------------------------------"
echo "Test Line 2" | sed 'i\Test Line 1'
echo "-----------------------------------"
echo "Test Line 2" | sed 'a\Test Line 1'

echo "-------------------------------------------"
sed '3i This is an inserted line.' data1.txt

echo "-----下面的例子是将一个新行附加到数据流中第三行后"
sed '3a This is an inserted line a dfadfadf.' data1.txt

echo "111111只要用代表数据最后一行的美元符就可以了。"
sed '$a This is an inserted line a dfadfadf.' data1.txt


# 修改行
#修改（change）命令允许修改数据流中整行文本的内容。它跟插入和附加命令的工作机制
# 一样，你必须在sed命令中单独指定新行。
echo "修改行-----------------"
sed '3c cccccccccccccccccccccccccccc' data1.txt

#在这个例子中， sed编辑器会修改第三行中的文本。也可以用文本模式来寻址。
echo "修改行-----------------"
sed '/number/c ccccccccccccccccccccccccccccccc' data1.txt

# 你可以在修改命令中使用地址区间，但结果未必如愿
echo "你可以在修改命令中使用地址区间，但结果未必如愿--"
sed '2,3c/ ccccccccccccccccccccccccccccccccc' data1.txt

# 转换命令
#转换（transform）命令（y）是唯一可以处理单个字符的sed编辑器命令。转换命令格式
#如下。
#[address]y/inchars/outchars/
#转换命令会对inchars和outchars值进行一对一的映射。 inchars中的第一个字符会被转
#换为outchars中的第一个字符，第二个字符会被转换成outchars中的第二个字符。这个映射过
#程会一直持续到处理完指定字符。如果inchars和outchars的长度不同，则sed编辑器会产生一
#条错误消息。
echo "令转换命令------------------------"
sed 'y/abcdefg/higklmn/' data1.txt


# p命令用来打印文本行；
echo "p命令用来打印文本行；" | sed 'p'
echo "p命令用来打印文本行；" | sed -n 'p'
sed -n '/number 3/p' data1.txt

# 如果需要在修改之前查看行，也可以使用打印命令，比如与替换或修改命令一起使用。
echo "如果需要在修改之前查看行，也可以使用打印命令，比如与替换或修改命令一起使用。"
#echo "Hello World" | sed -n '/H/{p s/ello/ELLO/p}'
echo "Hello World" | sed -n '/ello/{p;s/Hello/HELLO/p}'


# 打印行号
echo "----------------打印行号"
sed '=' data1.txt
sed -n '/number/{=;p}' data1.txt


# 列出行
# 制表符的位置使用\t来显示。行尾的美元符表示换行符。
echo "------------------列出行"
sed -n 'l' data1.txt













