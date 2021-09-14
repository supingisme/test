# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/sh

#操作符 说明 举例
#-b file检测文件是否是块设备文件，如果是，则返回 true。 
#[ -b $file ] 返回 false。

#-c file 检测文件是否是字符设备文件，如果是，则返回 true。 
#[ -b $file ] 返回 false。

#-d file检测文件是否是目录，如果是，则返回 true。 
#[ -d $file ] 返回 false。

#-f file 检测文件是否是普通文件（既不是目录，也不是设备文件），如果是，则返回 true。
#[ -f $file ] 返回 true。

#-g file检测文件是否设置了 SGID 位，如果是，则返回 true。 
#[ -g $file ] 返回 false。

#-k file 检测文件是否设置了粘着位(Sticky Bit)，如果是，则返回 true。 
#[ -k $file ] 返回 false。

#-p file检测文件是否是具名管道，如果是，则返回 true。 
#[ -p $file ] 返回 false。

#-u file检测文件是否设置了 SUID 位，如果是，则返回 true。 
#[ -u $file ] 返回 false。

#-r file 检测文件是否可读，如果是，则返回 true。 
#[ -r $file ] 返回 true。

#-w file检测文件是否可写，如果是，则返回 true。 
#[ -w $file ] 返回 true。

#-x file 检测文件是否可执行，如果是，则返回 true。 
#[ -x $file ] 返回 true。

#-s file 检测文件是否为空（文件大小是否大于0），不为空返回 true。 
#[ -s $file ] 返回 true。

#-e file检测文件（包括目录）是否存在，如果是，则返回 true。 
#[ -e $file ] 返回 true。

file="tmp.bash"

if [ -r $file ]
then
echo "File has read access"
else
echo "File does not have read access"
fi
if [ -w $file ]
then
echo "File has write permission"
else
echo "File does not have write permission"
fi
if [ -x $file ]
then
echo "File has execute permission"
else
echo "File does not have execute permission"
fi
if [ -f $file ]
then
echo "File is an ordinary file"
else
echo "This is sepcial file"
fi
if [ -d $file ]
then
echo "File is a directory"
else
echo "This is not a directory"
fi
if [ -s $file ]
then
echo "File size is zero"
else
echo "File size is not zero"
fi
if [ -e $file ]
then
echo "File exists"
else
echo "File does not exist"
fi
