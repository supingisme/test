/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 10月 09日 星期三 08:20:26 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>

void func()
{
	printf("func\n");
#define _FUNC___
}	

void select();

void fun_select()
{
	printf("%s\n", __func__);
}

#define CALLS(name, ...) fun_##name(__VA_ARGS__)

#define		MODULE_CFIG_MGMT  0x0100        //OM Configuration management module
#define     MODULE_MAIN_CTRL  0x0200        //OM main control module   
#define     MODULE_BORD_MGMT  0x0300        //OM board management module  
#define     MODULE_CELL_MGMT  0x0400        //OM virtual cell management module       
#define     MODULE_RRUS_MGMT  0x0500        //OM RRU management module
#define     MODULE_FTPS_MGMT  0x0600        //OM FTP module  
#define		MODULE_ALAR_MGMT  0x0700        //OM ALarm management module
#define		MODULE_INET_MGMT  0x0800        //OM netport msgs management module
#define		MODULE_TIMER	  0x0900

#define def define
//#def rong "rong"

#define rongtao
#if !defined(rongtao) && !defined(rongtao1) 
 #error "Must define one of rongtao and rongtao1"
#endif


int main(int argc, char *argv[])
{
	CALLS(select);
	
	if(argc > 2)
	{
#define _ARGC_
		func();
	}

#ifdef _FUNC___
	printf("define _FUNC_\n");
#endif

#if defined (_____________________)
	printf("undefined:____________________\n");
#endif

	return 0;
}
