/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:48 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:50 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:33 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:07 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/*********************** self documentation **********************/
/*****************************************************************************
SCAXIS - compute a readable scale for use in plotting axes

scaxis		compute a readable scale for use in plotting axes

******************************************************************************
Function Prototype:
void scaxis (float x1, float x2, int *nxnum, float *dxnum, float *fxnum);

******************************************************************************
Input:
x1		first x value
x2		second x value
nxnum		desired number of numbered values

Output:
nxnum		number of numbered values
dxnum		increment between numbered values (dxnum>0.0)
fxnum		first numbered value

******************************************************************************
Notes:
scaxis attempts to honor the user-specified nxnum.  However, nxnum
will be modified if necessary for readability.  Also, fxnum and nxnum
will be adjusted to compensate for roundoff error; in particular, 
fxnum will not be less than xmin-eps, and fxnum+(nxnum-1)*dxnum 
will not be greater than xmax+eps, where eps = 0.0001*(xmax-xmin).
xmin is the minimum of x1 and x2.  xmax is the maximum of x1 and x2.

******************************************************************************
Author:  Dave Hale, Colorado School of Mines, 01/13/89
*****************************************************************************/
/**************** end self doc ********************************/


#include "cwp.h"

void
scaxis (float x1, float x2, int *nxnum, float *dxnum, float *fxnum)
/*****************************************************************************
compute a readable scale for use in plotting axes
******************************************************************************
Input:
x1		first x value
x2		second x value
nxnum		desired number of numbered values

Output:
nxnum		number of numbered values
dxnum		increment between numbered values (dxnum>0.0)
fxnum		first numbered value
******************************************************************************
Notes:
scaxis attempts to honor the user-specified nxnum.  However, nxnum
will be modified if necessary for readability.  Also, fxnum and nxnum
will be adjusted to compensate for roundoff error; in particular, 
fxnum will not be less than xmin-eps, and fxnum+(nxnum-1)*dxnum 
will not be greater than xmax+eps, where eps = 0.0001*(xmax-xmin).
xmin is the minimum of x1 and x2.  xmax is the maximum of x1 and x2.
******************************************************************************
Author:  Dave Hale, Colorado School of Mines, 01/13/89
*****************************************************************************/
{
	int n,i,iloga;
	float d,f,rdint[4],eps,a,b,xmin,xmax;

	/* set readable intervals */
	rdint[0] = 1.0;  rdint[1] = 2.0;  rdint[2] = 5.0;  rdint[3] = 10.0;

	/* handle x1==x2 as a special case */
	if  (x1==x2) {
		*nxnum = 1;
		*dxnum = 1.0;
		*fxnum = x1;
		return;
	}

	/* determine minimum and maximum x */
	xmin = (x1<x2)?x1:x2;
	xmax = (x1>x2)?x1:x2;
	
	/* get desired number of numbered values */
	n = *nxnum;
	n = (2>n)?2:n;
	
	/* determine output parameters, adjusted for roundoff */
	a = (xmax-xmin)/(float)(n-1);
	iloga = (int)log10(a);
	if (a<1.0) iloga = iloga - 1;
	b = a/pow(10.0,(double)iloga);
	for (i=0; i<3 && b>=sqrt(rdint[i]*rdint[i+1]); i++);
	d = rdint[i]*pow(10.0,(float)iloga);
	f = ((int)(xmin/d))*d-d;
	eps = 0.0001*(xmax-xmin);
	while(f<(xmin-eps))
		 f = f+d;
	n = 1+(int)((xmax+eps-f)/d); 
        
	/* set output parameters before returning */
	*nxnum = n;
	*dxnum = d;
	*fxnum = f;
}
