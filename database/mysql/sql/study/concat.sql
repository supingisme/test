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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 18:23:34 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:34:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:15:34 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:12 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:05:15 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:01:40 CST. */
--Concat()拼接串，即把多个串连接起来形成一个较长的串。
--Concat()需要一个或多个指定的串，各个串之间用逗号分隔。
--上面的SELECT语句连接以下4个元素：
-- 存储在vend_name列中的名字；
-- 包含一个空格和一个左圆括号的串；
-- 存储在vend_country列中的国家；
-- 包含一个右圆括号的串。

use testdb;

select concat(name,'<',age,'>') from person where age is not NULL;

--删除数据右侧多余的空格来整理数据，这可以使用MySQL的RTrim()函数来完成
select concat(name,'<',RTrim(age),'>') from person;

--。别名（alias）是一个字段或值的替换名。别名用AS关键字赋予。请看下面的SELECT语句：
select concat(name,'<',RTrim(age),'>') as name_age from person;
/**
别名的其他用途 别名还有其他用途。常见的用途包括在实际
的表列名包含不符合规定的字符（如空格）时重新命名它，在
原来的名字含混或容易误解时扩充它，等等。
*/




