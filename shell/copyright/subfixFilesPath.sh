#!/bin/bash

# Rong tao 2019.09.20
function subfixFilsPath()
{
	if [ $# -lt 2 ]; then
		echo "usage: $0 [findSubfix] [rootDir]"
		return 
    else
        if [ ! -d $2 ]; then
            echo -e "\033[1;31m$2\033[m must be a exist directory"
            return
        fi
	fi
	for f in `ls $2`; do
		if [ -d $2/$f ]; then
			subfixFilsPath $1 $2/$f
		elif [ -f $2/$f ]; then
            # rongtao.c -> c; get rongtao.c 's subfix
			_subfix=${f##*.} 
			if [ $_subfix = $1 ]; then
				echo "#include \"$2/$f\""
			fi
		fi
	done
}

# Rong tao 2019.09.20
headerFile=header.h

:>$headerFile
subfixFilsPath  $* 1>>$headerFile

cat $headerFile

