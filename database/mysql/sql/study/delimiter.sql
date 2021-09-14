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
/**
mysql命令行客户机的分隔符 如果你使用的是mysql命令行
实用程序，应该仔细阅读此说明。
默认的MySQL语句分隔符为;（正如你已经在迄今为止所使用
的MySQL语句中所看到的那样）。mysql命令行实用程序也使
用;作为语句分隔符。如果命令行实用程序要解释存储过程自
身内的;字符，则它们最终不会成为存储过程的成分，这会使
存储过程中的SQL出现句法错误。
解决办法是临时更改命令行实用程序的语句分隔符，如下所示：
其中，DELIMITER //告诉命令行实用程序使用//作为新的语
句结束分隔符，可以看到标志存储过程结束的END定义为END
//而不是END;。这样，存储过程体内的;仍然保持不动，并且
正确地传递给数据库引擎。最后，为恢复为原来的语句分隔符，
可使用DELIMITER ;。
除\符号外，任何字符都可以用作语句分隔符。
如果你使用的是mysql命令行实用程序，在阅读本章时请记住
这里的内容。
*/

delimiter //

