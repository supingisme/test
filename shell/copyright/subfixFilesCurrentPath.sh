#!/bin/bash

# Rong tao 2019.09.20
function subfixFilsCurrentPath()
{
	if [ $# -lt 1 ]; then
		echo "usage: $0 [findSubfix]"
		return
	fi
    local list
    local path
    if [ $# -eq 2 ]; then
        list=$(ls $2)
        path="$2/"
    else
        list=$(ls)
        path=""
    fi
    
	for f in $list; do
    
		if [ -d $path$f ]; then
			subfixFilsCurrentPath $1 $path$f
            
		elif [ -f $path$f ]; then
            # rongtao.c -> c; get rongtao.c 's subfix
			local _subfix=${f##*.} 
			if [ $_subfix = $1 ]; then
				echo "#include \"$path$f\""
			fi
		fi
	done
}


# Rong tao 2019.09.20
function CrtlHeaderGenerater()
{
    if [ $# -lt 2 ]; then
		echo "usage: $0 [headerName] [HEADER_MACRO_H]"
        echo "       sh subfixFilesCurrentPath.sh  header.h __HEADER_H"
		return
	fi
    local headerFile=$1
    local macro_h=$2
    
    :>$headerFile
    echo "#ifndef $macro_h" 																	1>>$headerFile
    echo "#define $macro_h 1" 																	1>>$headerFile
    echo "" 																					1>>$headerFile
    echo "/**" 																					1>>$headerFile
	echo " *  Header of OpenCRTL" 																1>>$headerFile
	echo " *  crtl.h, Just includes the billions of OpenCRTL header files necessary to" 		1>>$headerFile
	echo " *  do whatever you want." 															1>>$headerFile
	echo " *  Time: $(date)" 															        1>>$headerFile
	echo " *  Author: RongTao" 															        1>>$headerFile
	echo " */" 																					1>>$headerFile
	echo "#include "rt_config.h"" 																1>>$headerFile
	echo "#include "rt_env.h"" 																	1>>$headerFile
    echo "" 																					1>>$headerFile
    echo "" 																					1>>$headerFile
	
    subfixFilsCurrentPath  h 																	1>>$headerFile
    
    echo "" 																					1>>$headerFile
    echo "#endif /*<$macro_h>*/" 																1>>$headerFile
    
    cat $headerFile
}

#CrtlHeaderGenerater $*