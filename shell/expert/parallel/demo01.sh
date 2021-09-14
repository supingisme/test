# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

function fun1
{
    Njob=5
    for((i=0;i<$Njob;i++));do
    {
        echo "progress $1 is sleeping for 3 seconds zzz..."
        sleep 1
    }
    done 
    #显示脚本耗时
    echo -e "time-consuming: $SECONDS seconds"
}

function fun2
{
    Njob=5
    for((i=0;i<$Njob;i++));do
    {
        echo "progress $1 is sleeping for 3 seconds zzz..."
        #循环内容放到后台执行；
        sleep 1 &
    }
    done 
    wait
    #显示脚本耗时
    echo -e "time-consuming: $SECONDS seconds"
}

fun2
