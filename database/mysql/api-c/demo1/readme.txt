# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:53 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:23:33 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:48 CST. 


export MYSQL_SERVER="localhost"
export MYSQL_USER="root"
export MYSQL_PASS="root "
export MYSQL_DB="testdb"

Create database
	make create_db
	./create_db

import schema table and sample data
	mysqldump -u <user> -p <db> < sqmple_data/dn.sql

get death notices
	make get_dn
	./get_dn

get frequency of death notices within date range
	make analyze_dn
	./analyze_dn "2019-03-01" "2019-03-11"
