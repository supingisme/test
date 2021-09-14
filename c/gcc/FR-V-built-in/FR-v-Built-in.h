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
 *	6.52.5 FR-V Built-in Functions
 *	GCC provides many FR-V-specifc built-in functions. In general, these functions are in
 *	tended to be compatible with those described by FR-V Family, Softune C/C++ Compiler
 *	Manual (V6), Fujitsu Semiconductor. The two exceptions are __MDUNPACKH and __MBTOHE,
 *	the gcc forms of which pass 128-bit values by pointer rather than by value.
 *	Most of the functions are named after specifc FR-V instructions. Such functions are said
 *	to be “directly mapped” and are summarized here in tabular form.
 *	6.52.5.1 Argument Types
 *	The arguments to the built-in functions can be divided into three groups: register numbers,
 *	compile-time constants and run-time values. In order to make this classifcation clear at a
 *	glance, the arguments and return values are given the following pseudo types:
 *	Pseudo type Real C type Constant? Description
 *	uh unsigned short No an unsigned halfword
 *	uw1 unsigned int No an unsigned word
 *	sw1 int No a signed word
 *	uw2 unsigned long long No an unsigned doubleword
 *	sw2 long long No a signed doubleword
 *	const int Yes an integer constant
 *	acc int Yes an ACC register number
 *	iacc int Yes an IACC register number
 *	These pseudo types are not defned by GCC, they are simply a notational convenience
 *	used in this manual.
 *	Arguments of type uh, uw1, sw1, uw2 and sw2 are evaluated at run time. They correspond
 *	to register operands in the underlying FR-V instructions.
 *	const arguments represent immediate operands in the underlying FR-V instructions.
 *	They must be compile-time constants.
 *	acc arguments are evaluated at compile time and specify the number of an accumulator
 *	register. For example, an acc argument of 2 will select the ACC2 register.
 *	iacc arguments are similar to acc arguments but specify the number of an IACC register.
 *	See see Section 6.52.5.5 [Other Built-in Functions], page 486 for more details.
 *	6.52.5.2 Directly-mapped Integer Functions
 *	The functions listed below map directly to FR-V I-type instructions.
 *	Function prototype Example usage Assembly output
 *	sw1 __ADDSS (sw1, sw1) c = __ADDSS (a, b) ADDSS a,b,c
 *	sw1 __SCAN (sw1, sw1) c = __SCAN (a, b) SCAN a,b,c
 *	sw1 __SCUTSS (sw1) b = __SCUTSS (a) SCUTSS a,b
 *	sw1 __SLASS (sw1, sw1) c = __SLASS (a, b) SLASS a,b,c
 *	void __SMASS (sw1, sw1) __SMASS (a, b) SMASS a,b
 *	void __SMSSS (sw1, sw1) __SMSSS (a, b) SMSSS a,b
 *	void __SMU (sw1, sw1) __SMU (a, b) SMU a,b
 *	sw2 __SMUL (sw1, sw1) c = __SMUL (a, b) SMUL a,b,c
 *	sw1 __SUBSS (sw1, sw1) c = __SUBSS (a, b) SUBSS a,b,c
 *	uw2 __UMUL (uw1, uw1) c = __UMUL (a, b) UMUL a,b,c
 *	6.52.5.3 Directly-mapped Media Functions
 *	The functions listed below map directly to FR-V M-type instructions.
 *	Function prototype Example usage Assembly output
 *	uw1 __MABSHS (sw1) b = __MABSHS (a) MABSHS a,b
 *	void __MADDACCS (acc, acc) __MADDACCS (b, a) MADDACCS a,b
 *	sw1 __MADDHSS (sw1, sw1) c = __MADDHSS (a, b) MADDHSS a,b,c
 *	uw1 __MADDHUS (uw1, uw1) c = __MADDHUS (a, b) MADDHUS a,b,c
 *	uw1 __MAND (uw1, uw1) c = __MAND (a, b) MAND a,b,c
 *	void __MASACCS (acc, acc) __MASACCS (b, a) MASACCS a,b
 *	uw1 __MAVEH (uw1, uw1) c = __MAVEH (a, b) MAVEH a,b,c
 *	uw2 __MBTOH (uw1) b = __MBTOH (a) MBTOH a,b
 *	void __MBTOHE (uw1 *, uw1) __MBTOHE (&b, a) MBTOHE a,b
 *	void __MCLRACC (acc) __MCLRACC (a) MCLRACC a
 *	void __MCLRACCA (void) __MCLRACCA () MCLRACCA
 *	uw1 __Mcop1 (uw1, uw1) c = __Mcop1 (a, b) Mcop1 a,b,c
 *	uw1 __Mcop2 (uw1, uw1) c = __Mcop2 (a, b) Mcop2 a,b,c
 *	uw1 __MCPLHI (uw2, const) c = __MCPLHI (a, b) MCPLHI a,#b,c
 *	uw1 __MCPLI (uw2, const) c = __MCPLI (a, b) MCPLI a,#b,c
 *	void __MCPXIS (acc, sw1, sw1) __MCPXIS (c, a, b) MCPXIS a,b,c
 *	void __MCPXIU (acc, uw1, uw1) __MCPXIU (c, a, b) MCPXIU a,b,c
 *	void __MCPXRS (acc, sw1, sw1) __MCPXRS (c, a, b) MCPXRS a,b,c
 *	void __MCPXRU (acc, uw1, uw1) __MCPXRU (c, a, b) MCPXRU a,b,c
 *	uw1 __MCUT (acc, uw1) c = __MCUT (a, b) MCUT a,b,c
 *	uw1 __MCUTSS (acc, sw1) c = __MCUTSS (a, b) MCUTSS a,b,c
 *	void __MDADDACCS (acc, acc) __MDADDACCS (b, a) MDADDACCS a,b
 *	void __MDASACCS (acc, acc) __MDASACCS (b, a) MDASACCS a,b
 *	uw2 __MDCUTSSI (acc, const) c = __MDCUTSSI (a, b) MDCUTSSI a,#b,c
*	uw2 __MDPACKH (uw2, uw2) c = __MDPACKH (a, b) MDPACKH a,b,c
*	uw2 __MDROTLI (uw2, const) c = __MDROTLI (a, b) MDROTLI a,#b,c
*	void __MDSUBACCS (acc, acc) __MDSUBACCS (b, a) MDSUBACCS a,b
*	void __MDUNPACKH (uw1 *, uw2) __MDUNPACKH (&b, a) MDUNPACKH a,b
*	uw2 __MEXPDHD (uw1, const) c = __MEXPDHD (a, b) MEXPDHD a,#b,c
*	uw1 __MEXPDHW (uw1, const) c = __MEXPDHW (a, b) MEXPDHW a,#b,c
*	uw1 __MHDSETH (uw1, const) c = __MHDSETH (a, b) MHDSETH a,#b,c
*	sw1 __MHDSETS (const) b = __MHDSETS (a) MHDSETS #a,b
*	uw1 __MHSETHIH (uw1, const) b = __MHSETHIH (b, a) MHSETHIH #a,b
*	sw1 __MHSETHIS (sw1, const) b = __MHSETHIS (b, a) MHSETHIS #a,b
*	uw1 __MHSETLOH (uw1, const) b = __MHSETLOH (b, a) MHSETLOH #a,b
*	sw1 __MHSETLOS (sw1, const) b = __MHSETLOS (b, a) MHSETLOS #a,b
*	uw1 __MHTOB (uw2) b = __MHTOB (a) MHTOB a,b
*	void __MMACHS (acc, sw1, sw1) __MMACHS (c, a, b) MMACHS a,b,c
*	void __MMACHU (acc, uw1, uw1) __MMACHU (c, a, b) MMACHU a,b,c
*	void __MMRDHS (acc, sw1, sw1) __MMRDHS (c, a, b) MMRDHS a,b,c
*	void __MMRDHU (acc, uw1, uw1) __MMRDHU (c, a, b) MMRDHU a,b,c
*	void __MMULHS (acc, sw1, sw1) __MMULHS (c, a, b) MMULHS a,b,c
*	void __MMULHU (acc, uw1, uw1) __MMULHU (c, a, b) MMULHU a,b,c
*	void __MMULXHS (acc, sw1, sw1) __MMULXHS (c, a, b) MMULXHS a,b,c
*	void __MMULXHU (acc, uw1, uw1) __MMULXHU (c, a, b) MMULXHU a,b,c
*	uw1 __MNOT (uw1) b = __MNOT (a) MNOT a,b
*	uw1 __MOR (uw1, uw1) c = __MOR (a, b) MOR a,b,c
*	uw1 __MPACKH (uh, uh) c = __MPACKH (a, b) MPACKH a,b,c
*	sw2 __MQADDHSS (sw2, sw2) c = __MQADDHSS (a, b) MQADDHSS a,b,c
*	uw2 __MQADDHUS (uw2, uw2) c = __MQADDHUS (a, b) MQADDHUS a,b,c
*	void __MQCPXIS (acc, sw2, sw2) __MQCPXIS (c, a, b) MQCPXIS a,b,c
*	void __MQCPXIU (acc, uw2, uw2) __MQCPXIU (c, a, b) MQCPXIU a,b,c
*	void __MQCPXRS (acc, sw2, sw2) __MQCPXRS (c, a, b) MQCPXRS a,b,c
*	void __MQCPXRU (acc, uw2, uw2) __MQCPXRU (c, a, b) MQCPXRU a,b,c
*	sw2 __MQLCLRHS (sw2, sw2) c = __MQLCLRHS (a, b) MQLCLRHS a,b,c
*	sw2 __MQLMTHS (sw2, sw2) c = __MQLMTHS (a, b) MQLMTHS a,b,c
*	void __MQMACHS (acc, sw2, sw2) __MQMACHS (c, a, b) MQMACHS a,b,c
*	void __MQMACHU (acc, uw2, uw2) __MQMACHU (c, a, b) MQMACHU a,b,c
*	void __MQMACXHS (acc, sw2, sw2) __MQMACXHS (c, a, b) MQMACXHS a,b,c
*	void __MQMULHS (acc, sw2, sw2) __MQMULHS (c, a, b) MQMULHS a,b,c
*	void __MQMULHU (acc, uw2, uw2) __MQMULHU (c, a, b) MQMULHU a,b,c
*	void __MQMULXHS (acc, sw2, sw2) __MQMULXHS (c, a, b) MQMULXHS a,b,c
*	void __MQMULXHU (acc, uw2, uw2) __MQMULXHU (c, a, b) MQMULXHU a,b,c
*	sw2 __MQSATHS (sw2, sw2) c = __MQSATHS (a, b) MQSATHS a,b,c
*	uw2 __MQSLLHI (uw2, int) c = __MQSLLHI (a, b) MQSLLHI a,b,c
*	sw2 __MQSRAHI (sw2, int) c = __MQSRAHI (a, b) MQSRAHI a,b,c
*	sw2 __MQSUBHSS (sw2, sw2) c = __MQSUBHSS (a, b) MQSUBHSS a,b,c
*	uw2 __MQSUBHUS (uw2, uw2) c = __MQSUBHUS (a, b) MQSUBHUS a,b,c
*	void __MQXMACHS (acc, sw2, sw2) __MQXMACHS (c, a, b) MQXMACHS a,b,c
*	void __MQXMACXHS (acc, sw2, sw2) __MQXMACXHS (c, a, b) MQXMACXHS a,b,c
*	uw1 __MRDACC (acc) b = __MRDACC (a) MRDACC a,b
*	uw1 __MRDACCG (acc) b = __MRDACCG (a) MRDACCG a,b
*	uw1 __MROTLI (uw1, const) c = __MROTLI (a, b) MROTLI a,#b,c
*	uw1 __MROTRI (uw1, const) c = __MROTRI (a, b) MROTRI a,#b,c
*	sw1 __MSATHS (sw1, sw1) c = __MSATHS (a, b) MSATHS a,b,c
*	uw1 __MSATHU (uw1, uw1) c = __MSATHU (a, b) MSATHU a,b,c
*	uw1 __MSLLHI (uw1, const) c = __MSLLHI (a, b) MSLLHI a,#b,c
*	sw1 __MSRAHI (sw1, const) c = __MSRAHI (a, b) MSRAHI a,#b,c
*	uw1 __MSRLHI (uw1, const) c = __MSRLHI (a, b) MSRLHI a,#b,c
*	void __MSUBACCS (acc, acc) __MSUBACCS (b, a) MSUBACCS a,b
*	sw1 __MSUBHSS (sw1, sw1) c = __MSUBHSS (a, b) MSUBHSS a,b,c
*	uw1 __MSUBHUS (uw1, uw1) c = __MSUBHUS (a, b) MSUBHUS a,b,c
*	void __MTRAP (void) __MTRAP () MTRAP
*	uw2 __MUNPACKH (uw1) b = __MUNPACKH (a) MUNPACKH a,b
*	uw1 __MWCUT (uw2, uw1) c = __MWCUT (a, b) MWCUT a,b,c
*	void __MWTACC (acc, uw1) __MWTACC (b, a) MWTACC a,b
*	void __MWTACCG (acc, uw1) __MWTACCG (b, a) MWTACCG a,b
*	uw1 __MXOR (uw1, uw1) c = __MXOR (a, b) MXOR a,b,c
*	6.52.5.4 Raw read/write Functions
*	This sections describes built-in functions related to read and write instructions to access
*	memory. These functions generate membar instructions to ﬂush the I/O load and stores
*	where appropriate, as described in Fujitsu’s manual described above.
*	unsigned char __builtin_read8 (void *data)
	*	unsigned short __builtin_read16 (void *data)
	*	unsigned long __builtin_read32 (void *data)
	*	unsigned long long __builtin_read64 (void *data)
	*	void __builtin_write8 (void *data, unsigned char datum)
	*	void __builtin_write16 (void *data, unsigned short datum)
	*	void __builtin_write32 (void *data, unsigned long datum)
	*	void __builtin_write64 (void *data, unsigned long long datum)
 *
 * 6.52.5.5 Other Built-in Functions
 * This section describes built-in functions that are not named after a specifc FR-V instruc
 * tion.
 * sw2 __IACCreadll (iacc reg)
	* Return the full 64-bit value of IACC0. The reg argument is reserved for future
	* expansion and must be 0.
	* sw1 __IACCreadl (iacc reg)
	* Return the value of IACC0H if reg is 0 and IACC0L if reg is 1. Other values
	* of reg are rejected as invalid.
	* void __IACCsetll (iacc reg, sw2 x)
	* Set the full 64-bit value of IACC0 to x. The reg argument is reserved for future
	* expansion and must be 0.
	* void __IACCsetl (iacc reg, sw1 x)
	* Set IACC0H to x if reg is 0 and IACC0L to x if reg is 1. Other values of reg
	* are rejected as invalid.
	* void __data_prefetch0 (const void *x)
	* Use the dcpl instruction to load the contents of address x into the data cache.
	* void __data_prefetch (const void *x)
	* Use the nldub instruction to load the contents of address x into the data cache.
	* The instruction will be issued in slot I1.
 */
