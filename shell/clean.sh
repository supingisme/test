# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:41 CST. 

function clean {
filename=("*.o" "*.a" "*.d" "*.gch" "*~" "test" "log_message*" "*.out" "*.so" "main")
for name in ${filename[@]}; do
    #echo $name
    find . -name $name -type f -print -exec rm -rf {} \;
done 
}


#Rong Tao's Copyright 
function Copyright
{
#Copyright=$PWD/Copyright
Copyright=Copyright
tmpfile=/tmp/$$.cright
Date=`date | awk '{print $0}'`
RT="Copyright (C) Rong Tao @Sylincom Beijing"

# have arguments
if [ $# -gt 1 ]; then
    echo "Usage: $ Copyright a.c or $ Copyright"
elif [ $# -eq 1 ]; then
    echo -e "\033[1;32mCopyright $1\033[0m"
    if [ -d $1 ]; then
        echo ""
        echo -e "Can't add copyright to a directory."
        echo ""
    elif [ .c = `echo $1 | sed 's/.*\.c/.c/'` -o \
          .cpp = `echo $1 | sed 's/.*\.cpp/.cpp/'` -o \
          .cc = `echo $1 | sed 's/.*\.cc/.cc/'` -o \
          .cxx = `echo $1 | sed 's/.*\.cxx/.cxx/'` -o \
          .h = `echo $1 | sed 's/.*\.h/.h/'` -o \
          .hxx = `echo $1 | sed 's/.*\.hxx/.hxx/'` -o \
		  .sql = `echo $1 | sed 's/.*\.sql/.sql/'` ]; then
        >$tmpfile
        echo "/* "$RT", $Date. */" >> $tmpfile
        #echo "" >> $tmpfile
        cat $1 >> $tmpfile
        #cat $tmpfile | grep Copyright
        mv -f $tmpfile $1
        
    elif [ .bash = `echo $1 | sed 's/.*\.bash/.bash/'` -o \
           .sh = `echo $1 | sed 's/.*\.sh/.sh/'` ]; then
        >$tmpfile
        echo "# "$RT", $Date. " >> $tmpfile
        #echo "" >> $tmpfile
        cat $1 >> $tmpfile
        #cat $tmpfile | grep Copyright
        mv -f $tmpfile $1
    else
        >$tmpfile
        echo " "$RT", $Date. " >> $tmpfile
        #echo "" >> $tmpfile
        cat $1 >> $tmpfile
        #cat $tmpfile | grep Copyright
        mv -f $tmpfile $1
    fi  
    return 0
fi

# don't have arguments
for i in `ls`
do
    echo -e "\033[1;32mCopyright $i\033[0m"
    if [ -d $i ]; then
        cd $i
        $Copyright
        cd ..
    elif # C file
        [ .c = `echo $i | sed 's/.*\.c/.c/'` -o \
          .cpp = `echo $i | sed 's/.*\.cpp/.cpp/'` -o \
          .cc = `echo $i | sed 's/.*\.cc/.cc/'` -o \
          .cxx = `echo $i | sed 's/.*\.cxx/.cxx/'` -o \
          .h = `echo $i | sed 's/.*\.h/.h/'` -o \
          .hxx = `echo $i | sed 's/.*\.hxx/.hxx/'` -o \
		  .sql = `echo $i | sed 's/.*\.sql/.sql/'` ]
        then
        >$tmpfile
        echo "/* "$RT", $Date. */" >> $tmpfile
        #echo "" >> $tmpfile
        cat $i >> $tmpfile
        #cat $tmpfile | grep Copyright
        mv -f $tmpfile $i
    elif # shell file
        [ .bash = `echo $i | sed 's/.*\.bash/.bash/'` -o \
          .sh = `echo $i | sed 's/.*\.sh/.sh/'`  ]
        then
        >$tmpfile
        echo "# "$RT", $Date. " >> $tmpfile
        #echo "" >> $tmpfile
        cat $i >> $tmpfile
        #cat $tmpfile | grep Copyright
        mv -f $tmpfile $i
    fi

done
}

