#!/bin/bash

file=base.txt
words=words.txt

string="auth_host"

line=`grep $string $file`
num=$(grep -n "$line" $file | awk -F ':' '{print $1}')

echo $num $line $file

#nump=1p
#exit
#until [ `sed -n $nump $file` == "" ]
#do
#	num=$(expr $num + 1)
##	nump=$num" p"
#	echo $num  $nump: "$line" : `sed -n $nump $file`
#done

numa=$num" r"

echo -e ">>>>$numa, $nump"

sed -i "$numa $words" $file
