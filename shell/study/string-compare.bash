# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:43 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:51 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. 
#!/bin/bash

#!/bin/bash
# mis-using string comparisons
#
val1=baseball
val2=Baseball
#
if [ $val1 \> $val2 ]
then
echo "$val1 is greater than $val2"
else
echo "$val1 is less than $val2"
fi

val1="rongtao"
val2="rongtao"

if [ $val1 = "rongtao" ]
then 
echo "$val1 is equal $val2"
else
echo "$val1 is not equal $val2"
fi
