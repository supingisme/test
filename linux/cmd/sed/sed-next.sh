# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:25 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:49 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:20 CST. 
#!/bin/bash

#一个删掉空白行的sed脚本
sed '/^$/d' data1.txt

#脚本要查找含有单词header的那一行。找到之后， n命令会让sed编辑器移动到文
#本的下一行，也就是那个空行。
echo "----------------------------------------------"
sed '/number 4/{n ; d}' data1.txt


#下面的例子演示了N命令的工作方式
echo "----------------------------------------------"
sed '/number/{N; s/\n/ /}' data1.txt
sed '/first/{ N ; s/\n/ / }' data1.txt

#替换命令会在文本文件中查找特定的双词短语System Administrator。如果短语在一行
#中的话，事情很好处理，替换命令可以直接替换文本。但如果短语分散在两行中的话，替换命令
#就没法识别匹配的模式了。
#这时N命令就可以派上用场了。
echo "----------------------------------------------"
sed 'N ; s/rong.tao/Rong Tao/g' data3.txt

