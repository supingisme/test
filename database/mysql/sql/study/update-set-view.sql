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


/*
，并非所有视图都是可更新的。基本上可以说，如果MySQL不
能正确地确定被更新的基数据，则不允许更新（包括插入和删除）。这实
际上意味着，如果视图定义中有以下操作，则不能进行视图的更新：
 分组（使用GROUP BY和HAVING）；
 联结；
 子查询；
 并；
 聚集函数（Min()、Count()、Sum()等）；
 DISTINCT；
 导出（计算）列。
*/

select * from f1;
/*
+-------------+-----------+
| customer_id | fname     |
+-------------+-----------+
|           3 | Alex      |
|           4 | Adrian    |
|           5 | Simon     |
|           6 | Neil      |
|           9 | Christine |
|          10 | Mike      |
|          11 | Dave      |
|          12 | Richard   |
|          13 | Laura     |
|          14 | Bill      |
|          15 | David     |
+-------------+-----------+
11 rows in set (0.01 sec)
*/

update f1 set  fname = 'asdfadsfadsfadf' ;

select * from f1;
/*
+-------------+-----------------+
| customer_id | fname           |
+-------------+-----------------+
|           3 | asdfadsfadsfadf |
|           4 | asdfadsfadsfadf |
|           5 | asdfadsfadsfadf |
|           6 | asdfadsfadsfadf |
|           9 | asdfadsfadsfadf |
|          10 | asdfadsfadsfadf |
|          11 | asdfadsfadsfadf |
|          12 | asdfadsfadsfadf |
|          13 | asdfadsfadsfadf |
|          14 | asdfadsfadsfadf |
|          15 | asdfadsfadsfadf |
+-------------+-----------------+
11 rows in set (0.00 sec)
*/
