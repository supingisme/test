# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 20日 星期四 08:47:53 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 19日 星期三 08:50:23 CST. 
#!/bin/bash
#对应的动态库连接插件
#
./server --address localhost --port 4000 &

#diskfree改为对应的动态库插件
firefox http://localhost:4000/diskfree &
