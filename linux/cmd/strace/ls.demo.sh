#!/bin/bash
# rongtao rtoax
# 显示完整的程序调用栈
strace -ff -o out ls -a 

# out 为输出的调用栈txt文件的前缀

