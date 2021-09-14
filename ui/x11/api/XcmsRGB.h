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
typedef double XcmsFloat;
typedef struct {
	unsigned short red; /* 0x0000 to 0xffff */
	unsigned short green; /* 0x0000 to 0xffff */
	unsigned short blue; /* 0x0000 to 0xffff */
} XcmsRGB; /* RGB Device */

typedef struct {
	XcmsFloat red; /* 0.0 to 1.0 */
	XcmsFloat green; /* 0.0 to 1.0 */
	XcmsFloat blue; /* 0.0 to 1.0 */
} XcmsRGBi; /* RGB Intensity */
typedef struct {
	XcmsFloat X;
	XcmsFloat Y; /* 0.0 to 1.0 */
	XcmsFloat Z;
} XcmsCIEXYZ; /* CIE XYZ */
typedef struct {
	XcmsFloat u_prime; /* 0.0 to ~0.6 */
	XcmsFloat v_prime; /* 0.0 to ~0.6 */
	XcmsFloat Y; /* 0.0 to 1.0 */
} XcmsCIEuvY; /* CIE u'v'Y */
typedef struct {
	XcmsFloat x; /* 0.0 to ~.75 */
	XcmsFloat y; /* 0.0 to ~.85 */
	XcmsFloat Y; /* 0.0 to 1.0 */
} XcmsCIExyY; /* CIE xyY */
typedef struct {
	XcmsFloat L_star; /* 0.0 to 100.0 */
	XcmsFloat a_star;
	XcmsFloat b_star;
} XcmsCIELab; /* CIE L*a*b* */
typedef struct {
	XcmsFloat L_star; /* 0.0 to 100.0 */
	XcmsFloat u_star;
	XcmsFloat v_star;
} XcmsCIELuv; /* CIE L*u*v* */
typedef struct {
	XcmsFloat H; /* 0.0 to 360.0 */
	XcmsFloat V; /* 0.0 to 100.0 */
	XcmsFloat C; /* 0.0 to 100.0 */
} XcmsTekHVC; /* TekHVC */
typedef struct {
	XcmsFloat pad0;
	XcmsFloat pad1;
	XcmsFloat pad2;
	XcmsFloat pad3;
} XcmsPad; /* four doubles */
