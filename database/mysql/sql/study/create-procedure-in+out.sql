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


use testdb;

/*
select * from goods;
+-------+-------+--------+
| name  | price | number |
+-------+-------+--------+
| books | 88.99 |    100 |
| pen   | 108.2 |     99 |
+-------+-------+--------+
2 rows in set (0.00 sec)
*/

delimiter //
create procedure pro2(
	in iname char(20),
	out oprice decimal(8,2)
)
begin
	select price*number as totalprice from goods where name = iname into oprice;
end //

call pro2('books', @price);

select @price;
/*
> call pro2('pen', @price);
Query OK, 1 row affected, 1 warning (0.00 sec)

> select @price;
+--------+
| @price |
+--------+
|  10712 |
+--------+
1 row in set (0.00 sec)

*/
