# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:59 CST. 
# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 18日 星期一 09:12:28 CST. 
#!/bin/bash

#初始化
sudo service postgresql initdb

#启动服务
sudo service postgresql start 

#查看状态
sudo service postgress status

#连接用户和数据库
#$ sudo su - username
#$ psql databasename
# databasename=#
