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



create view func as select * from customer;
select * from func;

--same as

select * from (select * from customer);
--但是这样用是不允许的
--ERROR 1248 (42000): Every derived table must have its own alias

create view f2 as select customer_id, fname, lname from customer where lname <> 'Stones';
select * from f2;
/*
+-------------+-----------+---------+
| customer_id | fname     | lname   |
+-------------+-----------+---------+
|           3 | Alex      | Matthew |
|           4 | Adrian    | Matthew |
|           5 | Simon     | Cozens  |
|           6 | Neil      | Matthew |
|           9 | Christine | Hickman |
|          10 | Mike      | Howard  |
|          11 | Dave      | Jones   |
|          12 | Richard   | Neill   |
|          13 | Laura     | Hardy   |
|          14 | Bill      | O'Neill |
|          15 | David     | Hudson  |
+-------------+-----------+---------+
11 rows in set (0.00 sec)

*/
