#!/bin/bash
# rongtao 2020.01.22

AUTHOR_DEF="Rong Tao"
DATE_DEF=`date +%Y/%m/%d`


function swap_str_to_c_style()
{
    local input="$1"
    
    c_style_str=${input//./_}
	c_style_str=${c_style_str//-/_}
	c_style_str=${c_style_str//:/_}
	c_style_str=${c_style_str//=/_}
	c_style_str=${c_style_str//+/_}

    echo $c_style_str && return
}

#生成 ld verbose原始文件，需要除去前后的注释内容
# rongtao 2020.01.22
function generate_ld_verbose_file()
{
	if [ $# -lt 1 ]; then
		echo "Usage: $0 [ld file name]"
		return 1
	fi
	
	ldfile=$1

	ld --verbose > $ldfile

	#删除最后一行
	sed -i '$d' $ldfile

	#行翻转
	tmpfile=`mktemp`
	findstring="========="

	tac $ldfile > $tmpfile
	findline=`grep $findstring $tmpfile`
	endline=`sed -n '$p' $tmpfile`

	until [[ $findline = $endline ]]
	do
		#echo "$findline VS $endline"
		#删除最后一行
		sed -i '$d' $tmpfile
		endline=`sed -n '$p' $tmpfile`
	done

	#删除最后一行
	sed -i '$d' $tmpfile

	tac $tmpfile > $ldfile

	#删除临时文件
	rm -rf $tmpfile
	
	return 0
}

# 在ld verbose文件中添加自定义的init section
# # rongtao 2020.01.22
function add_my_init_section_to_ld_verbose_file()
{
	if [ $# -lt 2 ]; then
		echo "Usage: $0 [ld file name] [my init section name]"
		return 1
	fi

	ldverbosefile=$1
	myinitsectionfile=$2

	string="__bss_start"

	line=`grep $string $ldverbosefile`
	num=$(grep -n "$line" $ldverbosefile | awk -F ':' '{print $1}')

	num=$(expr $num - 1)

	numa=$num" r"

	sed -i "$numa $myinitsectionfile" $ldverbosefile
	
	return 0
}

#生成section初始ld文件
#rongtao 
function generate_my_init_section_file()
{
	if [ $# -lt 2 ]; then
		echo "Usage: $0 [file name: exist will delete] [ld verbose section name]"
		return 1
	fi
	filename=$1
	init_section_name=$2

	#替换字符串中的“.” 为 “_”: 
	# .rong.tao -> _rong_tao
	base_init_section_name=$(swap_str_to_c_style $init_section_name)

	start_fn="__init${base_init_section_name}_start"
	end_fn="__init${base_init_section_name}_end"
	
	rm -f $filename

	echo "											" >> $filename
	echo "/* $init_section_name start **********/	" >> $filename
	echo "  $init_section_name : { 					" >> $filename
	echo "	/* . = ALIGN(4);*/						" >> $filename
	echo "	 $start_fn = .;							" >> $filename
	echo "		*($init_section_name*) 				" >> $filename
	echo "	 $end_fn = .;							" >> $filename
	echo "  }										" >> $filename
	echo "/* $init_section_name end *********/		" >> $filename
	echo "											" >> $filename
}

#生成section初始C语言头文件
#rongtao 
function generate_my_section_src_header_code()
{
	if [ $# -lt 2 ]; then
		echo "Usage: $0 [header file name] [ld verbose section name]"
		return 1
	fi
	
	filename=$1
	init_section_name=$2

	#替换字符串中的“.” 为 “_”: 
	# .rong.tao -> _rong_tao
	base_init_section_name=$(swap_str_to_c_style $init_section_name)

	start_fn="__init${base_init_section_name}_start"
	end_fn="__init${base_init_section_name}_end"

	#替换字符串中的“.” 为 “_”: 
	# .rong.tao -> _rong_tao -> _RONG_TAO_H -> ___RONG_TAO_H
	HDR_DEF="`echo __$base_init_section_name | tr '[a-z]' '[A-Z]'`"_H
	
	
	rm -f $filename
	
	echo "/**											" >> $filename
	echo " *  File:   init.h							" >> $filename
	echo " *  Author: $AUTHOR_DEF						" >> $filename
	echo " *  Time:   $DATE_DEF							" >> $filename
	echo " */											" >> $filename
	echo "#ifndef $HDR_DEF								" >> $filename
	echo "#define $HDR_DEF 1							" >> $filename
	echo "												" >> $filename
	echo "#define __SECTION		\"$init_section_name\"	" >> $filename
	echo "												" >> $filename
	echo "typedef int (*section_call_fn)(void);			" >> $filename
	echo "												" >> $filename
	echo "#define SECTION_FN_ADD(func) \				" >> $filename
	echo "    section_call_fn __section_fn_##func __attribute__((section(__SECTION))) = func	" >> $filename
	echo "																						" >> $filename
	echo "extern section_call_fn $start_fn;							" >> $filename
	echo "extern section_call_fn $end_fn;							" >> $filename
	echo "															" >> $filename
	echo "#ifdef __SECTION_LOG 										" >> $filename
	echo "#include <stdio.h>										" >> $filename
	echo "#define SECTION_LOG(fmt...) ({ \							" >> $filename
	echo "		int n = 0;\											" >> $filename
	echo "		n+=fprintf(stdout, \"[\"__SECTION\"] %s %s:%d \",\	" >> $filename
	echo "		        __FILE__, __func__, __LINE__);\				" >> $filename
	echo "		n+=fprintf(stdout, fmt);\							" >> $filename
	echo "		n;\													" >> $filename
	echo "	})														" >> $filename
	echo "#else													" >> $filename
	echo "#define SECTION_LOG(fmt...)							" >> $filename
	echo "#endif												" >> $filename
	echo "																" >> $filename
	echo "#define DO_SECTION_CALLS()  { \								" >> $filename
	echo "    section_call_fn *__call_fn_ptr = &$start_fn; \			" >> $filename
	echo "    while (__call_fn_ptr && __call_fn_ptr < &$end_fn) { \		" >> $filename
	echo "        SECTION_LOG (\"call_ptr: %p\n\", __call_fn_ptr); \	" >> $filename
	echo "        (*__call_fn_ptr)();  \								" >> $filename
	echo "        ++__call_fn_ptr; \									" >> $filename
	echo "    };\														" >> $filename
	echo "}\														" >> $filename
	echo "															" >> $filename
	echo "#endif /*<$HDR_DEF>*/										" >> $filename

	#去除行首的空格和tab
	#sed -i 's/^[ \t]*//g' $filename
	#去除行尾的空格和tab
	sed -i 's/[ \t]*$//g' $filename
	
	return 0
}

#生成section测试代码
#rongtao 
function generate_my_section_test_code()
{
	if [ $# -lt 3 ]; then
		echo "Usage: $0 [test code file name] [header code file name] [ld file name]"
		exit
	fi

	srcfile=$1
	hdrfile=$2
	ldfile=$3

	rm -f $srcfile
	
	echo "/**						" >> $srcfile
	echo " *  File:   $srcfile		" >> $srcfile
	echo " *  Author: $AUTHOR_DEF	" >> $srcfile
	echo " *  Time:   $DATE_DEF		" >> $srcfile
	echo " */						" >> $srcfile
	echo "#define __SECTION_LOG		" >> $srcfile
	echo "#include \"$hdrfile\"		" >> $srcfile
	echo "							" >> $srcfile
	echo "int section_func1()				" >> $srcfile
	echo "{									" >> $srcfile
	echo "    SECTION_LOG(\"log info\n\");	" >> $srcfile
	echo "};								" >> $srcfile
	echo "SECTION_FN_ADD(section_func1);	" >> $srcfile
	echo "									" >> $srcfile
	echo "int section_func2()				" >> $srcfile
	echo "{									" >> $srcfile
	echo "    SECTION_LOG(\"log info\n\");	" >> $srcfile
	echo "};								" >> $srcfile
	echo "SECTION_FN_ADD(section_func2);	" >> $srcfile
	echo "									" >> $srcfile
	echo "/**								" >> $srcfile
	echo " *  Function:   main				" >> $srcfile
	echo " *  Author:     $AUTHOR_DEF		" >> $srcfile
	echo " *  Time:       $DATE_DEF			" >> $srcfile
	echo " */								" >> $srcfile
	echo "int main()				" >> $srcfile
	echo "{							" >> $srcfile
	echo "    DO_SECTION_CALLS();	" >> $srcfile
	echo "    						" >> $srcfile
	echo "    return 0;				" >> $srcfile
	echo "}							" >> $srcfile

	#去除行首的空格和tab
	#sed -i 's/^[ \t]*//g' $srcfile
	#去除行尾的空格和tab
	sed -i 's/[ \t]*$//g' $srcfile

	#生成makefile
	file_makefile="makefile"

	rm -f $file_makefile

	include=`dirname $hdrfile`

	echo "SRC:=$srcfile								" >> $file_makefile
	echo "LD:=$ldfile								" >> $file_makefile
	echo "INC:=-I./ -I$include						" >> $file_makefile
	echo "											" >> $file_makefile
	echo "all:test									" >> $file_makefile
	echo "											" >> $file_makefile
	echo "test:${SRC} \${LD}						" >> $file_makefile
	echo "	gcc \${SRC} -T \${LD} \${INC} -o test	" >> $file_makefile
	echo "											" >> $file_makefile
	echo "clean:									" >> $file_makefile
	echo "	rm -rf test								" >> $file_makefile

	#去除行首的空格和tab
	#sed -i 's/^[ \t]*//g' $file_makefile
	#去除行尾的空格和tab
	sed -i 's/[ \t]*$//g' $file_makefile
	
	return 0
}


if [ $# -eq 0 ]; then
	file_ld="rongtao-ld.lds"
	file_section="rongtao-section.lds"
	file_src_hdr="rongtao-init.h"
	file_test_code="test-main.c"
	section_name=".rongtao+init-func:section=rong+-:." #C style string is best, you can include "+-=:." in the section string
elif [ $# -eq 5 ]; then

	file_ld=$1
	file_section=$2
	file_src_hdr=$4
	file_test_code=$5
	section_name=$3
	
elif [ $# -lt 5 ]; then
	
	echo -e "Usage: $0 [ld file name] [my init section file] [ld verbose section name] [src hdr file name] [test code file name]"
	exit
fi


#生成初始ld.lds文件
generate_ld_verbose_file $file_ld

#生成section在ld中的文本文件
generate_my_init_section_file $file_section $section_name

#向ld.lds中添加上面函数生成的section文件
add_my_init_section_to_ld_verbose_file $file_ld $file_section

#生成C语言头文件
generate_my_section_src_header_code $file_src_hdr $section_name

#生成C语言测试文件
generate_my_section_test_code $file_test_code $file_src_hdr $file_ld

