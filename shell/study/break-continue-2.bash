# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash
for var1 in 1 2 3
do
    for var2 in 0 5
    do
        if [ $var1 -eq 2 -a $var2 -eq 0 ]
        then
            break 2
        else
            echo "$var1 $var2"
            continue
        fi
    done
done


while :
do
    echo -n "Input a number between 1 to 5: "
    read aNum
    case $aNum in
        1|2|3|4|5) 
            echo "Your number is $aNum!"
            continue
            echo "Game is over!"
            ;;
        *) echo "You do not select a number between 1 to 5!"
            break
            echo "break"
            ;;
    esac
done


NUMS="1 2 3 4 5 6 7"
for NUM in $NUMS
do
    Q=`expr $NUM % 2`
    
    if [ $Q -eq 0 ]
    then
        echo "Number is an even number!! $Q"
        continue
    fi
    echo "Found odd number $Q"
done








