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

/*
UNION规则
正如所见，并是非常容易使用的。但在进行并时有几条规则需要注意。
 UNION必须由两条或两条以上的SELECT语句组成，语句之间用关
键字UNION分隔（因此，如果组合4条SELECT语句，将要使用3个
UNION关键字）。
 UNION中的每个查询必须包含相同的列、表达式或聚集函数（不过
各个列不需要以相同的次序列出）。
 列数据类型必须兼容：类型不必完全相同，但必须是DBMS可以
隐含地转换的类型（例如，不同的数值类型或不同的日期类型）。
如果遵守了这些基本规则或限制，则可以将并用于任何数据检索任务。
*/
use custome;

select customer_id from customer where customer_id <=4;
/**
+-------------+
| customer_id |
+-------------+
|          14 |
|          15 |
+-------------+
2 rows in set (0.00 sec)
*/

select customer_id from customer where customer_id >13;
/**
+-------------+
| customer_id |
+-------------+
|           1 |
|           2 |
|           3 |
|           4 |
+-------------+
4 rows in set (0.00 sec)
*/

select customer_id from customer where customer_id <=4
union
select customer_id from customer where customer_id >13;
/**
+-------------+
| customer_id |
+-------------+
|           1 |
|           2 |
|           3 |
|           4 |
|          14 |
|          15 |
+-------------+
6 rows in set (0.00 sec)
*/
