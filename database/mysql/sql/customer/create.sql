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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:23:34 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 17:26:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 17:14:21 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 17:08:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 17:03:02 CST. */
--mysql -uroot -p'root ' 'custome' < xxx.sql

CREATE TABLE customer ( 
    customer_id serial , 
    title char(4) ,
    fname varchar(32) , 
    lname varchar(32) NOT NULL, 
    addressline varchar(64) , 
    town varchar(32) , 
    zipcode char(10) NOT NULL, 
    phone varchar(16) , 
    CONSTRAINT customer_pk PRIMARY KEY(customer_id) 
);
CREATE TABLE item ( 
    item_id serial , 
    description varchar(64) NOT NULL, 
    cost_price numeric(7,2) , 
    sell_price numeric(7,2) , 
    CONSTRAINT item_pk PRIMARY KEY(item_id) 
);

CREATE TABLE orderinfo ( 
    orderinfo_id serial , 
    customer_id integer NOT NULL, 
    date_placed date NOT NULL, 
    date_shipped date , 
    shipping numeric(7,2) , 
    CONSTRAINT orderinfo_pk PRIMARY KEY(orderinfo_id) 
); 

CREATE TABLE stock ( 
    item_id integer NOT NULL, 
    quantity integer NOT NULL, 
    CONSTRAINT stock_pk PRIMARY KEY(item_id) 
);

CREATE TABLE orderline ( 
    orderinfo_id integer NOT NULL,
    item_id integer NOT NULL, 
    quantity integer NOT NULL, 
    CONSTRAINT orderline_pk PRIMARY KEY(orderinfo_id, item_id) 
); 

CREATE TABLE barcode ( 
    barcode_ean char(13) NOT NULL, 
    item_id integer NOT NULL, 
    CONSTRAINT barcode_pk PRIMARY KEY(barcode_ean) 
);
