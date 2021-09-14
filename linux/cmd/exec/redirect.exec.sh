#!/bin/bash

#*** demo1 ***
#创建文件描述符
exec 9<> a.out
#重定向
echo "Hello World!" >& 9

#*** demo2 ***
exec 7<> /dev/tcp/www.baidu.com/80
echo -e "GET / HTTP/1.0\n" 1>& 7
