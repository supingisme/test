#!/bin/bash
# Rong tao 2019.08.14
#	
function subfixFils()
{
	if [ $# -lt 1 ]; then
		echo "usage: $0 [extension name]"
		return 
	fi
	for f in `ls`; do
		if [ -d $f ]; then
			cd $f
			subfixFils $*
			cd ..
		elif [ -f $f ]; then
			_subfix=${f##*.} # rongtao.c -> c; get rongtao.c 's subfix
			if [ $_subfix = $1 ]; then
				echo -e " \033[1;32m$_subfix\033[m: $f "
				#TODO alter file context

			fi
		fi
	done
}

subfixFils  $*
