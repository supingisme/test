#!/bin/bash 
# 清理

# make clean -C ../src

rm -rf *.s *.kpatch *.stripped lpmake patchroot *.patch .kpatch*  .lpmaketmp *.rej

rm -rf `find -name *.lpmakeorig`
rm -rf `find -name .*.s`

for f in $(ls) 
do
	if [ `file $f | awk '{print $2}'` = "ELF" ]; then 
		echo delete ELF file $f;
		rm -f $f
	fi
done

make clean
