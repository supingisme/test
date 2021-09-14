/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:51 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:51 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:35 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */


/*********************** self documentation **********************/
/************************************************************************
WINDOW - windowing routines

hanningnWindow - returns an n element long hanning window 

************************************************************************
Function prototypes:
void hanningnWindow(int n,float *w);
************************************************************************
Author: Potash Corporation, Sascatchewan: Balasz Nemeth given to CWP 2008
************************************************************************/

/**************** end self doc ********************************/
	

#include "cwp.h"

void hanningnWindow(int n,float *w)
/************************************************************************
hanningnWindow - returns an n element long hanning window 
************************************************************************
Input:
n	size of window
w	hanning window function of size n
************************************************************************
Notes:
	w[k] = 0.5(1-cos(2PI * K/n+1)) k=1,....n
************************************************************************
Author: Potash Corporation, Sascatchewan: Balasz Nemeth, given to CWP 2008
************************************************************************/
	
{
	int i;
	float PI2=2.0*PI;
	
	for(i=0;i<n;i++) 
		w[i] = 0.5*(1-cos(PI2*(i+1)/(n+1)));		
}
