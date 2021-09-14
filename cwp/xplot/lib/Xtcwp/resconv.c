/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:52 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:52 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:09 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/*********************** self documentation **********************/
/******************************************************************************
RESCONV - general purpose resource type converters

XtcwpStringToFloat	convert  string to float in resource

*******************************************************************************
Function Prototype:
void XtcwpStringToFloat (XrmValue *args, int *nargs, 
	XrmValue *fromVal, XrmValue *toVal);

*******************************************************************************
Author:  Dave Hale, Colorado School of Mines, 08/28/90
******************************************************************************/
/**************** end self doc ********************************/

#include "Xtcwp/Xtcwp.h"

void XtcwpStringToFloat (XrmValue *args, int *nargs, 
	XrmValue *fromVal, XrmValue *toVal)
{
	static float result;
	
	/* ensure number of arguments is zero */
	if (*nargs!=(args-args)/*0*/)
		XtWarning("String to Float conversion needs no arguments!");
	
	/* convert string in fromVal to float in toVal */
	if (sscanf((char *)fromVal->addr,"%f",&result)==1) {

		/* toVal points to the result */
		toVal->size = sizeof(float); 
		toVal->addr = (char *)&result;
	
	/* if sscanf fails */
	} else {
		XtStringConversionWarning((char *)fromVal->addr,"Float");
	}
}
