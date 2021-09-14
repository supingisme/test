# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:42 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
wc -l << EOF
    This is a simple lookup program
    for good (and bad) restaurants
    in Cape Town.
EOF


more << FLAG
    rong 
    *.*
    "\n"
FLAG


cat << EOF
    This is a simple lookup program
    for good (and bad) restaurants
    in Cape Town.
EOF


filename=test.txt
vi $filename << EndOfCommands
i
This file was created automatically from
a shell script
^[
ZZ
EndOfCommands
