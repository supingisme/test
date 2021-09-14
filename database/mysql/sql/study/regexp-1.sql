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
元 字 符 说 明
\\f 换页
\\n 换行
\\r 回车
\\t 制表
\\v 纵向制表
*/

select * from person where name regexp '[a-z]ao';

select * from person where name regexp '%\\.tao';

/**
匹配字符类
[:alnum:] 任意字母和数字（同[a-zA-Z0-9]）
[:alpha:] 任意字符（同[a-zA-Z]）
[:blank:] 空格和制表（同[\\t]）
[:cntrl:] ASCII控制字符（ASCII 0到31和127）
[:digit:] 任意数字（同[0-9]）
[:graph:] 与[:print:]相同，但不包括空格
[:lower:] 任意小写字母（同[a-z]）
[:print:] 任意可打印字符
[:punct:] 既不在[:alnum:]又不在[:cntrl:]中的任意字符
[:space:] 包括空格在内的任意空白字符（同[\\f\\n\\r\\t\\v]）
[:upper:] 任意大写字母（同[A-Z]）
[:xdigit:] 任意十六进制数字（同[a-fA-F0-9]）
*/


/*
匹配多个实例
元 字 符 说 明
* 0个或多个匹配
+ 1个或多个匹配（等于{1,}）
? 0个或1个匹配（等于{0,1}）
{n} 指定数目的匹配
{n,} 不少于指定数目的匹配
{n,m} 匹配数目的范围（m不超过255）
 */

/*
定位符
元 字 符 说 明
^ 文本的开始
$ 文本的结尾
[[:<:]] 词的开始
[[:>:]] 词的结尾
 */



