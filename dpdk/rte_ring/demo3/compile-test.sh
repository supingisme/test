#!/bin/bash

rm -f *.out

for file in `ls test_*`
do 
	echo "Compile $file -> ${file%.*}.out"
	gcc $file  async_ring.c -pthread -I./ -o ${file%.*}.out -w
done


