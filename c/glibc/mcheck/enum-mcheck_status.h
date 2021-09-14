/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 06月 20日 星期四 08:25:12 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 20日 星期四 08:25:06 CST. */


enum mcheck_status
{
	MCHECK_DISABLED = -1,	//consistency checking is not turned on 一致性检查未打开
	MCHECK_OK,				//block is fine
	MCHECK_FREE,			//block freed twice 
	MCHECK_HEAD,			//memory before the block was clobbered 堆内存块的头部越界
	MCHECK_TAIL,			//memory after the block was clobbered 堆内存块的尾部越界
};
