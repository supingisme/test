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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 14:43:22 CST. */
use testdb;

/*
仅为正则表达式语言的一个子集 如果你熟悉正则表达式，需
要注意：MySQL仅支持多数正则表达式实现的一个很小的子
集。本章介绍MySQL支持的大多数内容。
*/
select name,id from product where name regexp 'book|flower';

select * from product where name regexp '[abc]ook';
select * from product where name regexp '[a|b|c]ook';
