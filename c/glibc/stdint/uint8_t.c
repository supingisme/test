/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*	• int8 t
 *	• int16 t
 *	• int32 t
 *	• int64 t
 *	• uint8 t
 *	• uint16 t
 *	• uint32 t
 *	• uint64 t
 *
 *
 *	• int least8 t
 *	• int least16 t
 *	• int least32 t
 *	• int least64 t
 *	• uint least8 t
 *	• uint least16 t
 *	• uint least32 t
 *	• uint least64 t
 *
 *	• int fast8 t
 *	• int fast16 t
 *	• int fast32 t
 *	• int fast64 t
 *	• uint fast8 t
 *	• uint fast16 t
 *	• uint fast32 t
 *	• uint fast64 t
 *
 *	• intmax t
 *	• uintmax t
 *
 *
 *	[RongTao@localhost include]$ grep int_least stdint.h 
 *	typedef signed char		int_least8_t;
 *	typedef short int		int_least16_t;
 *	typedef int			int_least32_t;
 *	typedef long int		int_least64_t;
 *	typedef long long int		int_least64_t;
 *	typedef unsigned char		uint_least8_t;
 *	typedef unsigned short int	uint_least16_t;
 *	typedef unsigned int		uint_least32_t;
 *	typedef unsigned long int	uint_least64_t;
 *	typedef unsigned long long int	uint_least64_t;
 *	[RongTao@localhost include]$ grep -e int_least -e int8_t stdint.h 
 *	#ifndef __int8_t_defined
 *	# define __int8_t_defined
 *	typedef signed char		int8_t;
 *	typedef unsigned char		uint8_t;
 *	typedef signed char		int_least8_t;
 *	typedef short int		int_least16_t;
 *	typedef int			int_least32_t;
 *	typedef long int		int_least64_t;
 *	typedef long long int		int_least64_t;
 *	typedef unsigned char		uint_least8_t;
 *	typedef unsigned short int	uint_least16_t;
 *	typedef unsigned int		uint_least32_t;
 *	typedef unsigned long int	uint_least64_t;
 *	typedef unsigned long long int	uint_least64_t;
 *	[RongTao@localhost include]$ grep -e int_fast stdint.h 
 *	typedef signed char		int_fast8_t;
 *	typedef long int		int_fast16_t;
 *	typedef long int		int_fast32_t;
 *	typedef long int		int_fast64_t;
 *	typedef int			int_fast16_t;
 *	typedef int			int_fast32_t;
 *	typedef long long int		int_fast64_t;
 *	typedef unsigned char		uint_fast8_t;
 *	typedef unsigned long int	uint_fast16_t;
 *	typedef unsigned long int	uint_fast32_t;
 *	typedef unsigned long int	uint_fast64_t;
 *	typedef unsigned int		uint_fast16_t;
*	typedef unsigned int		uint_fast32_t;
*	typedef unsigned long long int	uint_fast64_t;
*	[RongTao@localhost include]$ grep -e int_max stdint.h 
*	[RongTao@localhost include]$ grep -e intmax stdint.h 
*	typedef long int		intmax_t;
*	typedef unsigned long int	uintmax_t;
*	typedef long long int		intmax_t;
*	typedef unsigned long long int	uintmax_t;
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	

	return 0;
}	
