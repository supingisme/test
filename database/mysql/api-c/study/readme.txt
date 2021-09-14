# Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:54 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:23:33 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:12:17 CST. 
connector-c-examples
====================

A collection of MySQL/MariaDB C API examples

Disclaimer: these are my private example files, they are *not* official MySQL documents
and are not supported by MySQL AB in any way


 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 17:20:50 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 14:00:31 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 13:38:03 CST. 
 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 11:33:18 CST. 



fetch : 拿来，取来，吸引，接来
stmt:	预处理
	预处理是先提交sql语句到服务端，执行预编译，客户端执行sql语句时，只需上传输入参数即可，这点
	和存储过程有点相似；一般而言，预处理语句执行效率相对于一般的sql执行操作而言，效率比较高，
	由于客户端上传的伙食读取的结果集是绑定输入内存地址和输出内存地址，对于一些二进制流，
	或大数据量的存储和读取显得尤为方便。
	mysql_init()：初始胡爱一个mysql对象，用于与数据库的连接句柄；
	mysql_real_connect（）：
	mysql_stmt_prepare()：长传预处理的sql语句
	mysql_stmt_bind_param()：定义相应的MYSQL_BIND数据结构，调用，用于绑定输入参数
	mysql_stmt_result_metadata()：如果由输出结果集，调用，以MYSQL_RES形式返回预处理语句元数据
	mysql_stmt_execute()：执行响应的sql查询操作
	mysql_stmt_bind_result()：
		如果有输出结果，调用mysql_stmt_bind_result()将数据绑定到MYSQL_BIND数据结构对象上
		同时调用mysql_stmt_store_result()将所有的结果集保存到客户端的缓冲区中
		并通过mysql_stmt_fetch()来进行调用获取返回的每一行的值。

