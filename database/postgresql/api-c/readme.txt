# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:59 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 13:46:59 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 10:02:18 CST. 

include PostgreSQL header
	#include <libpq-fe.h>
	#include <libpq-events.h>
	#include <libpq/libpq-fs.h>	

Folder      
	/usr/include/libpq/libpq-fs.h

Library
	/usr/lib64/libpq.so 
	: -lpq

test:
	$ sudo su - rongtao
	[sudo] rongtao 的密码：
	上一次登录：五 3月 15 13:24:59 CST 2019pts/0 上
	[rongtao@localhost ~]$ psql testdb
	psql (9.2.21)
		输入 "help" 来获取帮助信息.

		testdb=# select * from cars;
	 id |    name    | price  
	----+------------+--------
	  1 | Audi       |  52642
	  2 | Mercedes   |  57127
	  3 | Skoda      |   9000
	  4 | Volvo      |  29000
	  5 | Bentley    | 350000
	  6 | Citroen    |  21000
	  7 | Hummer     |  41400
	  8 | Volkswagen |  23700
	  9 | Mazda      |  27770
	  (9 行记录)
