/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. */
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
 *	6.52.9.3 MIPS-3D Built-in Functions
 *	The MIPS-3D Application-Specifc Extension (ASE) includes additional paired-single in
 *	structions that are designed to improve the performance of 3D graphics operations. Support
 *	for these instructions is controlled by the ‘-mips3d’ command-line option.
 *	The functions listed below map directly to a particular MIPS-3D instruction. Please refer
 *	to the architecture specifcation for more details on what each instruction does.
 *	v2sf __builtin_mips_addr_ps (v2sf, v2sf)
 *	Reduction add (addr.ps).
 *	v2sf __builtin_mips_mulr_ps (v2sf, v2sf)
 *	Reduction multiply (mulr.ps).
 *	v2sf __builtin_mips_cvt_pw_ps (v2sf)
 *	Convert paired single to paired word (cvt.pw.ps).
 *	v2sf __builtin_mips_cvt_ps_pw (v2sf)
 *	Convert paired word to paired single (cvt.ps.pw).
 *	float __builtin_mips_recip1_s (float)
 *	double __builtin_mips_recip1_d (double)
 *	v2sf __builtin_mips_recip1_ps (v2sf)
 *	Reduced precision reciprocal (sequence step 1) (recip1.fmt).
 *	float __builtin_mips_recip2_s (float, float)
 *	double __builtin_mips_recip2_d (double, double)
 *	v2sf __builtin_mips_recip2_ps (v2sf, v2sf)
 *	Reduced precision reciprocal (sequence step 2) (recip2.fmt).
 *	float __builtin_mips_rsqrt1_s (float)
 *	double __builtin_mips_rsqrt1_d (double)
 *	v2sf __builtin_mips_rsqrt1_ps (v2sf)
 *	Reduced precision reciprocal square root (sequence step 1) (rsqrt1.fmt).
 *	float __builtin_mips_rsqrt2_s (float, float)
 *	double __builtin_mips_rsqrt2_d (double, double)
 *	v2sf __builtin_mips_rsqrt2_ps (v2sf, v2sf)
 *	Reduced precision reciprocal square root (sequence step 2) (rsqrt2.fmt).
 *	The following multi-instruction functions are also available. In each case, cond can be
 *	any of the 16 ﬂoating-point conditions: f, un, eq, ueq, olt, ult, ole, ule, sf, ngle, seq,
 *	ngl, lt, nge, le or ngt.
 *	int __builtin_mips_cabs_cond_s (float a, float b)
 *	int __builtin_mips_cabs_cond_d (double a, double b)
 *	Absolute comparison of two scalar values (cabs.cond.fmt, bc1t/bc1f).
 *	These functions compare a and b using cabs.cond.s or cabs.cond.d and re
 *	turn the result as a boolean value. For example:
 *	float a, b;
 *	if (__builtin_mips_cabs_eq_s (a, b))
 *	true ();
 *	else
 *	false ();
 *	int __builtin_mips_upper_cabs_cond_ps (v2sf a, v2sf b)
 *	int __builtin_mips_lower_cabs_cond_ps (v2sf a, v2sf b)
 *	Absolute comparison of two paired-single values (cabs.cond.ps, bc1t/bc1f).
 *	These functions compare a and b using cabs.cond.ps and return either the
 *	upper or lower half of the result. For example:
 *	v2sf a, b;
 *	if (__builtin_mips_upper_cabs_eq_ps (a, b))
 *	upper_halves_are_equal ();
 *	else
 *	upper_halves_are_unequal ();
 *	if (__builtin_mips_lower_cabs_eq_ps (a, b))
 *	lower_halves_are_equal ();
 *	else
 *	lower_halves_are_unequal ();
 *	v2sf __builtin_mips_movt_cabs_cond_ps (v2sf a, v2sf b, v2sf c, v2sf d)
 *	v2sf __builtin_mips_movf_cabs_cond_ps (v2sf a, v2sf b, v2sf c, v2sf d)
 *	Conditional move based on absolute comparison (cabs.cond.ps,
 *	movt.ps/movf.ps).
 *	The movt functions return the value x computed by:
 *	cabs.cond.ps cc,a,b
 *	mov.ps x,c
 *	movt.ps x,d,cc
 *	The movf functions are similar but use movf.ps instead of movt.ps.
 *	int __builtin_mips_any_c_cond_ps (v2sf a, v2sf b)
 *	int __builtin_mips_all_c_cond_ps (v2sf a, v2sf b)
 *	int __builtin_mips_any_cabs_cond_ps (v2sf a, v2sf b)
 *	int __builtin_mips_all_cabs_cond_ps (v2sf a, v2sf b)
*	Comparison of two paired-single values (c.cond.ps/cabs.cond.ps,
		*	bc1any2t/bc1any2f).
*	These functions compare a and b using c.cond.ps or cabs.cond.ps. The any
*	forms return true if either result is true and the all forms return true if both
*	results are true. For example:
*	v2sf a, b;
*	if (__builtin_mips_any_c_eq_ps (a, b))
	*	one_is_true ();
	*	else
	*	both_are_false ();
	*	if (__builtin_mips_all_c_eq_ps (a, b))
	*	both_are_true ();
	*	else
	*	one_is_false ();
	*	int __builtin_mips_any_c_cond_4s (v2sf a, v2sf b, v2sf c, v2sf d)
	*	int __builtin_mips_all_c_cond_4s (v2sf a, v2sf b, v2sf c, v2sf d)
	*	int __builtin_mips_any_cabs_cond_4s (v2sf a, v2sf b, v2sf c, v2sf d)
	*	int __builtin_mips_all_cabs_cond_4s (v2sf a, v2sf b, v2sf c, v2sf d)
	*	Comparison of four paired-single values (c.cond.ps/cabs.cond.ps,
			*	bc1any4t/bc1any4f).
	*	These functions use c.cond.ps or cabs.cond.ps to compare a with b and to
	*	compare c with d. The any forms return true if any of the four results are true
	*	and the all forms return true if all four results are true. For example:
	*	v2sf a, b, c, d;
	*	if (__builtin_mips_any_c_eq_4s (a, b, c, d))
	*	some_are_true ();
	*	else
	*	all_are_false ();
	*	if (__builtin_mips_all_c_eq_4s (a, b, c, d))
	*	all_are_true ();
	*	else
	*	some_are_false ();
 */
