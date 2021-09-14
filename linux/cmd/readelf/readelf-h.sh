#!/bin/bash

# 显示文件头信息
readelf -h a.out
# ELF 头：
#   Magic：  7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
#   类别:                              ELF64
#   数据:                              2 补码，小端序 (little endian)
#   版本:                              1 (current)
#   OS/ABI:                            UNIX - System V
#   ABI 版本:                          0
#   类型:                              EXEC (可执行文件)
#   系统架构:                          Advanced Micro Devices X86-64
#   版本:                              0x1
#   入口点地址：              0x400440
#   程序头起点：              64 (bytes into file)
#   Start of section headers:          6440 (bytes into file)
#   标志：             0x0
#   本头的大小：       64 (字节)
#   程序头大小：       56 (字节)
#   Number of program headers:         9
#   节头大小：         64 (字节)
#   节头数量：         30
#   字符串表索引节头： 29
