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
 *	7.4 #pragma interface and implementation
 *	#pragma interface and #pragma implementation provide the user with a way of explicitly
 *	directing the compiler to emit entities with vague linkage (and debugging information) in a
 *	particular translation unit.
 *	Note: As of GCC 2.7.2, these #pragmas are not useful in most cases, because of COMDAT
 *	support and the “key method” heuristic mentioned in Section 7.3 [Vague Linkage], page 566.
 *	Using them can actually cause your program to grow due to unnecessary out-of-line copies
 *	of inline functions. Currently (3.4) the only beneft of these #pragmas is reduced duplication
 *	of debugging information, and that should be addressed soon on DWARF 2 targets with
 *	the use of COMDAT groups.
 *	#pragma interface
 *	#pragma interface "subdir/objects.h"
 *	Use this directive in header fles that defne object classes, to save space in
 *	most of the object fles that use those classes. Normally, local copies of certain
 *	information (backup copies of inline member functions, debugging information,
 *	and the internal tables that implement virtual functions) must be kept in each
 *	object fle that includes class defnitions. You can use this pragma to avoid such
 *	duplication. When a header fle containing ‘#pragma interface’ is included in
 *	a compilation, this auxiliary information will not be generated (unless the main
 *	input source fle itself uses ‘#pragma implementation’). Instead, the object
 *	fles will contain references to be resolved at link time.
 *	The second form of this directive is useful for the case where you have multiple
 *	headers with the same name in diﬀerent directories. If you use this form, you
 *	must specify the same string to ‘#pragma implementation’.
 *
 *
 *
 *
 *	#pragma implementation
 *	#pragma implementation "objects.h"
 *	Use this pragma in a main input fle, when you want full output from included
 *	header fles to be generated (and made globally visible). The included header
 *	fle, in turn, should use ‘#pragma interface’. Backup copies of inline member
 *	functions, debugging information, and the internal tables used to implement
 *	virtual functions are all generated in implementation fles.
 *	If you use ‘#pragma implementation’ with no argument, it applies to an
 *	include fle with the same basename1 as your source fle. For example, in
 *	‘allclass.cc’, giving just ‘#pragma implementation’ by itself is equivalent
 *	to ‘#pragma implementation "allclass.h"’.
 *	In versions of GNU C++ prior to 2.6.0 ‘allclass.h’ was treated as an im
 *	plementation fle whenever you would include it from ‘allclass.cc’ even if
 *	you never specifed ‘#pragma implementation’. This was deemed to be more
 *	trouble than it was worth, however, and disabled.
 *	Use the string argument if you want a single implementation fle to include code
 *	from multiple header fles. (You must also use ‘#include’ to include the header
 *	fle; ‘#pragma implementation’ only specifes how to use the fle—it doesn’t
 *	actually include it.)
 *	There is no way to split up the contents of a single header fle into multiple
 *	implementation fles.
 *	‘#pragma implementation’ and ‘#pragma interface’ also have an eﬀect on function in
 *	lining.
 *	If you defne a class in a header fle marked with ‘#pragma interface’, the eﬀect on
 *	an inline function defned in that class is similar to an explicit extern declaration—the
 *	compiler emits no code at all to defne an independent version of the function. Its defnition
 *	is used only for inlining with its callers.
 *	Conversely, when you include the same header fle in a main source fle that declares it
 *	as ‘#pragma implementation’, the compiler emits code for the function itself; this defnes
 *	a version of the function that can be found via pointers (or by callers compiled without
 *	inlining). If all calls to the function can be inlined, you can avoid emitting the function
 *	by compiling with ‘-fno-implement-inlines’. If any calls were not inlined, you will get
 *	linker errors.
 *
 *
 */

#include <stdio.h>

#pragma interface "object.h"



int main()
{
	interface1();
    
    struct object obj;
}

int interface1()
{
	printf("interface1");
	interface2();
}
int interface2()
{
	printf("interface2\n");
}
