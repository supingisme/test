# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:22 CST. 
#!/bin/bash

# Define your function here
Hello () {
    echo "Url is http://see.xidian.edu.cn/cpp/shell/"
}
# Invoke your function
Hello


funWithReturn(){
    echo "The function is to get the sum of two numbers..."
    echo -n "Input first number: "
    read aNum
    echo -n "Input another number: "
    read anotherNum
    echo "The two numbers are $aNum and $anotherNum !"
    return $(($aNum+$anotherNum))
}

funWithReturn

# Capture value returnd by last command
ret=$?
echo "The sum of two numbers is $ret !"


# Calling one function from another
number_one () {
    echo "Url_1 is http://see.xidian.edu.cn/cpp/shell/"
    number_two
}
number_two () {
    echo "Url_2 is http://see.xidian.edu.cn/cpp/u/xitong/"
}
number_one
