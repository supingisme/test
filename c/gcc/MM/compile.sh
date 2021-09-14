# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. 
#!/bin/bash

# check file is changed or not
# return 0: no need to compile
#        1: need compile
function changed
{
    file_time="debug"
    if [ ! -e $file_time ]; then
        echo -e "\033[31mmkdir $file_time\033[0m"
        mkdir $file_time
    fi
    if [ $# -lt 1 ]; then
        echo -e "\033[31mNeed an arg. Usage: $0 [filename]\033[0m"
        return 0
    fi
    
    if [ ! -e $1 ]; then
        echo -e "\033[31mNo such file: $1\033[0m"
        return 0
    fi
    
    change_time_file=$file_time/$1.stat
    change_time_file_dir=`dirname $change_time_file`
    if [ ! -e $change_time_file_dir ]; then
        echo -e "\033[31mCreate directory\033[0m: $change_time_file_dir"
        mkdir -p $change_time_file_dir
    fi
    if [ ! -e $change_time_file ]; then
        echo -e "\033[31mCreate file\033[0m: $change_time_file"
        touch $change_time_file
        t1="999"
    else 
        t1=`cat $change_time_file`  
    fi
    
    t2=`stat $1 -c %Y`

    if [ $t1 = $t2 ]; then
        echo "$1 don\'t need to compile."
        return 0
    else
        echo "$1 need to compile."
        echo $t2 > $change_time_file
        return 1
    fi
}

################################################################################
#
#
JT_SRAN_ROOT=$PWD
JT_SRAN="jt_sran"
#
INCLUDE     =("-I$JT_SRAN_ROOT/cell_mgmt_include")
INCLUDE    +=("-I/usr/include/libxml2 ")
#
LIBS =("-lnetsnmp" "-lnetsnmpmibs" "-lnetsnmpagent" "-lpthread" "-lxml2" "-ldl" "-lrt" "-lconfig")
#
DEP=()
#
################################################################################

# compile one file
# .c to .o
function compiled1
{
    if [ $# -lt 1 ]; then
        echo -e "\033[31mNeed an arg. Usage: $0 [filename]\033[0m"
        return 0
    fi
    gcc $1 -c -o `echo $S | sed 's/\.c/\.o/g'` $INCLUDE $LIBS
    
    return 1
}


SRC=("$JT_SRAN_ROOT/cell_mgmt/src/cell_mgmt_init.c" 
     "$JT_SRAN_ROOT/om_main.c")
     



     
for S in ${SRC[@]}
do
    DEP+=(`echo $S | sed 's/\.c/\.o/g'`)
    changed $S
    if [ $? -eq 1 ]; then
        compiled1 $S
    fi
done

echo ${DEP[@]}

