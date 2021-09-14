#!/bin/bash

filename=rongtao.tar.gz

echo "${filename%%.*}"

echo "${filename%.*}"

echo "${filename#*.}"

echo "${filename##*.}"

#运行结果：
#  sh extension.sh 
#rongtao
#rongtao.tar
#tar.gz
#gz

