#!/bin/bash

# 程序终止信号 ，产生 coredump 文件
kill -ABRT $(pidof ls)

# 对 coredump 文件解析
eu-readelf -n coredump.pidfile
