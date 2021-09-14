/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:54 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:16 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:26 CST. */
typedef unsigned long XcmsColorFormat; /* Color Specification Format */
typedef struct {
	union {
		XcmsRGB RGB;
		XcmsRGBi RGBi;
		XcmsCIEXYZ CIEXYZ;
		XcmsCIEuvY CIEuvY;
		XcmsCIExyY CIExyY;
		XcmsCIELab CIELab;
		XcmsCIELuv CIELuv;
		XcmsTekHVC TekHVC;
		XcmsPad Pad;
	} spec;
	unsigned long pixel;
	XcmsColorFormat format;
} XcmsColor; /* Xcms Color Structure */
