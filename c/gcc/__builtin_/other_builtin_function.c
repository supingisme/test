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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/**
 *	6.51 Other built-in functions provided by GCC
 *	GCC provides a large number of built-in functions other than the ones mentioned above.
 *	Some of these are for internal use in the processing of exceptions or variable-length argument
 *	lists and will not be documented here because they may change from time to time; we do
 *	not recommend general use of these functions.
 *	The remaining functions are provided for optimization purposes.
 *	GCC includes built-in versions of many of the functions in the standard C library. The
 *	versions prefxed with __builtin_ will always be treated as having the same meaning as
 *	the C library function even if you specify the ‘-fno-builtin’ option. (see Section 3.4 [C
 *	Dialect Options], page 28) Many of these functions are only optimized in certain cases; if
 *	they are not optimized in a particular case, a call to the library function will be emitted.
 *	Outside strict ISO C mode (‘-ansi’, ‘-std=c90’ or ‘-std=c99’), the functions _exit,
 *	alloca, bcmp, bzero, dcgettext, dgettext, dremf, dreml, drem, exp10f, exp10l, exp10,
 *	ffsll, ffsl, ffs, fprintf_unlocked, fputs_unlocked, gammaf, gammal, gamma, gammaf_
 *	r, gammal_r, gamma_r, gettext, index, isascii, j0f, j0l, j0, j1f, j1l, j1, jnf, jnl, jn,
 *	lgammaf_r, lgammal_r, lgamma_r, mempcpy, pow10f, pow10l, pow10, printf_unlocked,
 *	rindex, scalbf, scalbl, scalb, signbit, signbitf, signbitl, signbitd32, signbitd64,
 *	signbitd128, significandf, significandl, significand, sincosf, sincosl, sincos,
 *	stpcpy, stpncpy, strcasecmp, strdup, strfmon, strncasecmp, strndup, toascii, y0f,
 *	y0l, y0, y1f, y1l, y1, ynf, ynl and yn may be handled as built-in functions. All these
 *	functions have corresponding versions prefxed with __builtin_, which may be used even
 *	in strict C90 mode.
 *	The ISO C99 functions _Exit, acoshf, acoshl, acosh, asinhf, asinhl, asinh,
 *	atanhf, atanhl, atanh, cabsf, cabsl, cabs, cacosf, cacoshf, cacoshl, cacosh, cacosl,
 *	cacos, cargf, cargl, carg, casinf, casinhf, casinhl, casinh, casinl, casin, catanf,
 *	catanhf, catanhl, catanh, catanl, catan, cbrtf, cbrtl, cbrt, ccosf, ccoshf, ccoshl,
 *	ccosh, ccosl, ccos, cexpf, cexpl, cexp, cimagf, cimagl, cimag, clogf, clogl, clog,
 *	conjf, conjl, conj, copysignf, copysignl, copysign, cpowf, cpowl, cpow, cprojf,
 *	cprojl, cproj, crealf, creall, creal, csinf, csinhf, csinhl, csinh, csinl, csin,
 *	csqrtf, csqrtl, csqrt, ctanf, ctanhf, ctanhl, ctanh, ctanl, ctan, erfcf, erfcl,
 *	erfc, erff, erfl, erf, exp2f, exp2l, exp2, expm1f, expm1l, expm1, fdimf, fdiml, fdim,
 *	fmaf, fmal, fmaxf, fmaxl, fmax, fma, fminf, fminl, fmin, hypotf, hypotl, hypot,
 *	ilogbf, ilogbl, ilogb, imaxabs, isblank, iswblank, lgammaf, lgammal, lgamma, llabs,
 *	llrintf, llrintl, llrint, llroundf, llroundl, llround, log1pf, log1pl, log1p,
 *	log2f, log2l, log2, logbf, logbl, logb, lrintf, lrintl, lrint, lroundf, lroundl,
 *	lround, nearbyintf, nearbyintl, nearbyint, nextafterf, nextafterl, nextafter,
 *	nexttowardf, nexttowardl, nexttoward, remainderf, remainderl, remainder, remquof,
 *	remquol, remquo, rintf, rintl, rint, roundf, roundl, round, scalblnf, scalblnl,
 *	scalbln, scalbnf, scalbnl, scalbn, snprintf, tgammaf, tgammal, tgamma, truncf,
 *	truncl, trunc, vfscanf, vscanf, vsnprintf and vsscanf are handled as built-in
 *	functions except in strict ISO C90 mode (‘-ansi’ or ‘-std=c90’).
 *	There are also built-in versions of the ISO C99 functions acosf, acosl, asinf, asinl,
 *	atan2f, atan2l, atanf, atanl, ceilf, ceill, cosf, coshf, coshl, cosl, expf, expl,
 *	fabsf, fabsl, floorf, floorl, fmodf, fmodl, frexpf, frexpl, ldexpf, ldexpl, log10f,
 *	log10l, logf, logl, modfl, modf, powf, powl, sinf, sinhf, sinhl, sinl, sqrtf, sqrtl,
 *	tanf, tanhf, tanhl and tanl that are recognized in any mode since ISO C90 reserves these
 *	names for the purpose to which ISO C99 puts them. All these functions have corresponding
 *	versions prefxed with __builtin_.
 *	The ISO C94 functions iswalnum, iswalpha, iswcntrl, iswdigit, iswgraph, iswlower,
 *	iswprint, iswpunct, iswspace, iswupper, iswxdigit, towlower and towupper are han
 *	dled as built-in functions except in strict ISO C90 mode (‘-ansi’ or ‘-std=c90’).
 *	The ISO C90 functions abort, abs, acos, asin, atan2, atan, calloc, ceil, cosh,
 *	cos, exit, exp, fabs, floor, fmod, fprintf, fputs, frexp, fscanf, isalnum, isalpha,
 *	iscntrl, isdigit, isgraph, islower, isprint, ispunct, isspace, isupper, isxdigit,
 *	tolower, toupper, labs, ldexp, log10, log, malloc, memchr, memcmp, memcpy, memset,
 *	modf, pow, printf, putchar, puts, scanf, sinh, sin, snprintf, sprintf, sqrt, sscanf,
 *	strcat, strchr, strcmp, strcpy, strcspn, strlen, strncat, strncmp, strncpy, strpbrk,
 *	strrchr, strspn, strstr, tanh, tan, vfprintf, vprintf and vsprintf are all recognized
 *	as built-in functions unless ‘-fno-builtin’ is specifed (or ‘-fno-builtin-function’ is
 *	specifed for an individual function). All of these functions have corresponding versions
 *	prefxed with __builtin_.
 *	GCC provides built-in versions of the ISO C99 ﬂoating point comparison macros that
 *	avoid raising exceptions for unordered operands. They have the same names as the stan
 *	dard macros ( isgreater, isgreaterequal, isless, islessequal, islessgreater, and
 *	isunordered) , with __builtin_ prefxed. We intend for a library implementor to be
 *	able to simply #define each standard macro to its built-in equivalent. In the same fash
 *	ion, GCC provides fpclassify, isfinite, isinf_sign and isnormal built-ins used with
 *	__builtin_ prefxed. The isinf and isnan builtins appear both with and without the
 *	__builtin_ prefx.
 */
