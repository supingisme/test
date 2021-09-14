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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 10:12:28 CST. */

use custome;

select customer.customer_id, item.item_id from customer inner join item on customer.customer_id = item.item_id;
/*
+-------------+---------+
| customer_id | item_id |
+-------------+---------+
|           1 |       1 |
|           2 |       2 |
|           3 |       3 |
|           4 |       4 |
|           5 |       5 |
|           6 |       6 |
|           7 |       7 |
|           8 |       8 |
|           9 |       9 |
|          10 |      10 |
|          11 |      11 |
+-------------+---------+
11 rows in set (0.00 sec)
*/

select customer.customer_id, item.item_id from customer left outer join item on customer.customer_id = item.item_id;
/*
+-------------+---------+
| customer_id | item_id |
+-------------+---------+
|           1 |       1 |
|           2 |       2 |
|           3 |       3 |
|           4 |       4 |
|           5 |       5 |
|           6 |       6 |
|           7 |       7 |
|           8 |       8 |
|           9 |       9 |
|          10 |      10 |
|          11 |      11 |
|          12 |    NULL |
|          13 |    NULL |
|          14 |    NULL |
|          15 |    NULL |
+-------------+---------+
15 rows in set (0.00 sec)
*/


select customer.customer_id, item.item_id from customer right outer join item on customer.customer_id = item.item_id;
/*
+-------------+---------+
| customer_id | item_id |
+-------------+---------+
|           1 |       1 |
|           2 |       2 |
|           3 |       3 |
|           4 |       4 |
|           5 |       5 |
|           6 |       6 |
|           7 |       7 |
|           8 |       8 |
|           9 |       9 |
|          10 |      10 |
|          11 |      11 |
+-------------+---------+
11 rows in set (0.00 sec)
*/










