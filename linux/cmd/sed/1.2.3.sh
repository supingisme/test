# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:25 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:49 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:20 CST. 
#!/bin/bash

echo 'Hello hello world.' | sed 's,\(ello\)[ :]\(world\),\1.1 \2.2 ,g'

#Hello hello.1 world.2 .
