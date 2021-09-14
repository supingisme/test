/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*	struct utsname [Data Type]
 *	The utsname structure is used to hold information returned by the uname function.
 *	It has the following members:
 *	char sysname[]
 *	This is the name of the operating system in use.
 *	char release[]
 *	This is the current release level of the operating system implementation.
 *	char version[]
 *	This is the current version level within the release of the operating system.
 *	char machine[]
 *	This is a description of the type of hardware that is in use.
 *	Some systems provide a mechanism to interrogate the kernel directly
 *	for this information. On systems without such a mechanism, the GNU C
 *	library flls in this feld based on the confguration name that was specifed
 *	when building and installing the library.
 *	GNU uses a three-part name to describe a system confguration; the three
 *	parts are cpu, manufacturer and system-type, and they are separated
 *	with dashes. Any possible combination of three names is potentially
 *	meaningful, but most such combinations are meaningless in practice and
 *	even the meaningful ones are not necessarily supported by any particular
 *	GNU program.
 *	Since the value in machine is supposed to describe just the
 *	hardware, it consists of the frst two parts of the confguration name:
 *	‘cpu-manufacturer’. For example, it might be one of these:
 *	"sparc-sun", "i386-anything", "m68k-hp", "m68k-sony",
 *	"m68k-sun", "mips-dec"
 *	char nodename[]
 *	This is the host name of this particular computer. In the GNU C library,
 *	the value is the same as that returned by gethostname; see Section 30.1
 *	[Host Identifcation], page 754.
 *	gethostname() is implemented with a call to uname().
 *	char domainname[]
 *	This is the NIS or YP domain name. It is the same value returned by
 *	getdomainname; see Section 30.1 [Host Identifcation], page 754. This
 *	element is a relatively recent invention and use of it is not as portable as
 *	use of the rest of the structure.
 */
