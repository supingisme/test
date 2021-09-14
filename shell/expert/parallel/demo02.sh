# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

Njobs=15
Nproc=5

function PushQue{ #将PID值追加到队列中
    Que="$Que $1"
    Nrun=$(($Nrun+1))
}

function GenQue { #更新队列信息，先清空队列信息，然后检索生成新的队列信息
    OldQue=$Que
    Que="";Nrun=0
    for PID in $OldQue; do
        if [[ -d /proc/$PID ]]; then 
            PushQue $PID
        fi
    done
}

function ChkQue { #监察队列信息，如果有已经结束的进程的PID，那么更新队列信息
    OldQue=$Que
    for PID in $OldQue; do
        if [[ ! -d /proc/$PID ]]; then 
            GenQue $PID
        fi
    done
}

for((i=1; i<=Njobs; i++)); do 
    echo "progress $1 is sleeping for 3 seconds zzz..."
    sleep 3 &
    PID=$!
    PushQue $PID
    while [[ $Nrun -ge $Nproc ]]; do 
        ChkQue
        sleep 0.1
    done
done 
wait 

echo -e "time-consuming: $SECONDS seconds"
