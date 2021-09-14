/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:56 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:54 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 16:09:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 15:51:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 15:38:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 13:59:12 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 13:23:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 11:24:37 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 11:09:05 CST. */


create table customers 
(
	id int NOT NULL AUTO_INCREMENT,
	name char(50) NOT NULL,
	addr char(50) NULL,
	city char(50) NULL,
	state char(50) NULL,
	zip char(50) NULL,
	country char(50) NULL,
	contact char(50) NULL,
	email char(255) NULL,
	PRIMARY KEY (id) 
)ENGINE=InnoDB;
--表的主键可以在创建表时用  PRIMARY KEY关键字指定

create table orders
(
	order_num int NOT NULL AUTO_INCREMENT,
	order_date datetime NOT NULL,
	cust_id int NOT NULL,
	PRIMARY KEY (order_num)
)ENGINE=InnoDB;

create table venders
(
	id int NOT NULL AUTO_INCREMENT,
	name char(50) NOT NULL,
	addr char(50) NULL,
	city char(50) NULL,
	state char(50) NULL,
	zip char(50) NULL,
	country char(50) NULL,
	contact char(50) NULL,
	email char(255) NULL,
	PRIMARY KEY (id)
)ENGINE=InnoDB;


create table orderitems
(
	order_num int NOT NULL,
	order_item int NOT NULL,
	prod_id char(10) NOT NULL,
	quantity int NOT NULL default 1,
	item_price decimal(8,2) NOT NULL,
	PRIMARY KEY (order_num, order_item)
)ENGINE=InnoDB;







