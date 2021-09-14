#!/bin/bash

pattern_cmp_file=""profile
pattern_line="ulimit -q "
pattern_word=`echo $pattern_line | awk '{print $1$2$3$4$5$6$7}'`
echo $pattern_word

pattern_cmp_file_word=`cat $pattern_cmp_file | awk '{print $1$2$3$4$5$6$7}'`
echo $pattern_cmp_file_word

#pattern_cmp=`echo $pattern_cmp_file_word | grep $pattern_word`
#echo $pattern_cmp
if [[ $pattern_cmp_file_word =~ $pattern_word ]]; then
	echo "包含"
else
	echo "不包含"
fi
