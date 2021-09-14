/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:09 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	6.52.14 SPARC VIS Built-in Functions
 *	GCC supports SIMD operations on the SPARC using both the generic vector extensions
 *	(see Section 6.47 [Vector Extensions], page 379) as well as built-in functions for the SPARC
 *	Visual Instruction Set (VIS). When you use the ‘-mvis’ switch, the VIS extension is exposed
 *	as the following built-in functions:
 *	typedef int v2si __attribute__ ((vector_size (8)));
 *	typedef short v4hi __attribute__ ((vector_size (8)));
 *	typedef short v2hi __attribute__ ((vector_size (4)));
 *	typedef char v8qi __attribute__ ((vector_size (8)));
 *	typedef char v4qi __attribute__ ((vector_size (4)));
 *	void * __builtin_vis_alignaddr (void *, long);
 *	int64_t __builtin_vis_faligndatadi (int64_t, int64_t);
 *	v2si __builtin_vis_faligndatav2si (v2si, v2si);
 *	v4hi __builtin_vis_faligndatav4hi (v4si, v4si);
 *	v8qi __builtin_vis_faligndatav8qi (v8qi, v8qi);
 *	v4hi __builtin_vis_fexpand (v4qi);
 *	v4hi __builtin_vis_fmul8x16 (v4qi, v4hi);
 *	v4hi __builtin_vis_fmul8x16au (v4qi, v4hi);
 *	v4hi __builtin_vis_fmul8x16al (v4qi, v4hi);
 *	v4hi __builtin_vis_fmul8sux16 (v8qi, v4hi);
 *	v4hi __builtin_vis_fmul8ulx16 (v8qi, v4hi);
 *	v2si __builtin_vis_fmuld8sux16 (v4qi, v2hi);
 *	v2si __builtin_vis_fmuld8ulx16 (v4qi, v2hi);
 *	v4qi __builtin_vis_fpack16 (v4hi);
 *	v8qi __builtin_vis_fpack32 (v2si, v2si);
 *	v2hi __builtin_vis_fpackfix (v2si);
 *	v8qi __builtin_vis_fpmerge (v4qi, v4qi);
 *	int64_t __builtin_vis_pdist (v8qi, v8qi, int64_t);
 */
