/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:27 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:09 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:21 CST. */
#define _syscall6(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4, \
			  type5,arg5,type6,arg6) \
type name (type1 arg1,type2 arg2,type3 arg3,type4 arg4,type5 arg5,type6 arg6) \
{ \
	  register long __a __asm__ ("r10") = (long) arg1; \
	  register long __b __asm__ ("r11") = (long) arg2; \
	  register long __c __asm__ ("r12") = (long) arg3; \
	  register long __d __asm__ ("r13") = (long) arg4; \
	  register long __n_ __asm__ ("r9") = (__NR_##name); \
	  __asm__ __volatile__ (".ifnc %0%1%3%4%5,$r10$r9$r11$r12$r13\n\t" \
						".err\n\t" \
						".endif\n\t" \
						"move %6,$mof\n\tmove %7,$srp\n\t" \
						"break 13" \
						: "=r" (__a) \
						: "r" (__n_), "0" (__a), "r" (__b), \
						  "r" (__c), "r" (__d), "g" (arg5), "g" (arg6)\
						: "srp"); \
	  if (__a >= 0) \
	     return (type) __a; \
	  errno = -__a; \
	  return (type) -1; \
}
