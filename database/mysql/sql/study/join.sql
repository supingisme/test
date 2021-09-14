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

select customer_id, item_id, title,fname, description from customer,item where customer.customer_id = item.item_id;
/*
应该保证所有联结都有WHERE子句
+-------------+---------+-------+-----------+---------------+
| customer_id | item_id | title | fname     | description   |
+-------------+---------+-------+-----------+---------------+
|           1 |       1 | Miss  | Jenny     | Wood Puzzle   |
|           2 |       2 | Mr    | Andrew    | Rubik Cube    |
|           3 |       3 | Miss  | Alex      | Linux CD      |
|           4 |       4 | Mr    | Adrian    | Tissues       |
|           5 |       5 | Mr    | Simon     | Picture Frame |
|           6 |       6 | Mr    | Neil      | Fan Small     |
|           7 |       7 | Mr    | Richard   | Fan Large     |
|           8 |       8 | Mrs   | Ann       | Toothbrush    |
|           9 |       9 | Mrs   | Christine | Roman Coin    |
|          10 |      10 | Mr    | Mike      | Carrier Bag   |
|          11 |      11 | Mr    | Dave      | Speakers      |
+-------------+---------+-------+-----------+---------------+
11 rows in set (0.00 sec)

*/
