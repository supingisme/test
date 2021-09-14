/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:39 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
/*
 *	-M Instead of outputting the result of preprocessing, output a rule suitable for make
 *	describing the dependencies of the main source fle. The preprocessor outputs
 *	one make rule containing the object fle name for that source fle, a colon, and
 *	the names of all the included fles, including those coming from ‘-include’ or
 *	‘-imacros’ command line options.
 *	Unless specifed explicitly (with ‘-MT’ or ‘-MQ’), the object fle name consists of
 *	the name of the source fle with any sufx replaced with object fle sufx and
 *	with any leading directory parts removed. If there are many included fles then
 *	the rule is split into several lines using ‘\’-newline. The rule has no commands.
 *	This option does not suppress the preprocessor’s debug output, such as ‘-dM’.
 *	To avoid mixing such debug output with the dependency rules you should ex
 *	plicitly specify the dependency output fle with ‘-MF’, or use an environment
 *	variable like DEPENDENCIES_OUTPUT (see Chapter 13 [Environment Variables],
 *	page 65). Debug output will still be sent to the regular output stream as normal.
 *	Passing ‘-M’ to the driver implies ‘-E’, and suppresses warnings with an implicit
 *	‘-w’.
 *	-MM Like ‘-M’ but do not mention header fles that are found in system header
 *	directories, nor header fles that are included, directly or indirectly, from such
 *	a header.
 *	This implies that the choice of angle brackets or double quotes in an ‘#include’
 *	directive does not in itself determine whether that header will appear in ‘-MM’
 *	dependency output. This is a slight change in semantics from GCC versions
 *	3.0 and earlier.
 *	-MF file When used with ‘-M’ or ‘-MM’, specifes a fle to write the dependencies to. If
 *	no ‘-MF’ switch is given the preprocessor sends the rules to the same place it
 *	would have sent preprocessed output.
 *	When used with the driver options ‘-MD’ or ‘-MMD’, ‘-MF’ overrides the default
 *	dependency output fle.
 *
 *	-MG In conjunction with an option such as ‘-M’ requesting dependency generation,
 *	‘-MG’ assumes missing header fles are generated fles and adds them to the
 *	dependency list without raising an error. The dependency flename is taken
 *	directly from the #include directive without prepending any path. ‘-MG’ also
 *	suppresses preprocessed output, as a missing header fle renders this useless.
 *	This feature is used in automatic updating of makefles.
 *	-MP This option instructs CPP to add a phony target for each dependency other
 *	than the main fle, causing each to depend on nothing. These dummy rules
 *	work around errors make gives if you remove header fles without updating the
 *	‘Makefile’ to match.
 *	This is typical output:
 *	test.o: test.c test.h
 *	test.h:
 *	-MT target
 *	Change the target of the rule emitted by dependency generation. By default
 *	CPP takes the name of the main input fle, deletes any directory components
 *	and any fle sufx such as ‘.c’, and appends the platform’s usual object sufx.
 *	The result is the target.
 *	An ‘-MT’ option will set the target to be exactly the string you specify. If you
 *	want multiple targets, you can specify them as a single argument to ‘-MT’, or
 *	use multiple ‘-MT’ options.
 *	For example, ‘-MT ’$(objpfx)foo.o’’ might give
 *	$(objpfx)foo.o: foo.c
 *	-MQ target
 *	Same as ‘-MT’, but it quotes any characters which are special to Make.
 *	‘-MQ ’$(objpfx)foo.o’’ gives
 *	$$(objpfx)foo.o: foo.c
 *	The default target is automatically quoted, as if it were given with ‘-MQ’.
 *	-MD ‘-MD’ is equivalent to ‘-M -MF file’, except that ‘-E’ is not implied. The driver
 *	determines fle based on whether an ‘-o’ option is given. If it is, the driver uses
 *	its argument but with a sufx of ‘.d’, otherwise it takes the name of the input
 *	fle, removes any directory components and sufx, and applies a ‘.d’ sufx.
 *	If ‘-MD’ is used in conjunction with ‘-E’, any ‘-o’ switch is understood to specify
 *	the dependency output fle (see [-MF], page 58), but if used without ‘-E’, each
 *	‘-o’ is understood to specify a target object fle.
 *	Since ‘-E’ is not implied, ‘-MD’ can be used to generate a dependency output
 *	fle as a side-eﬀect of the compilation process.
 *	-MMD Like ‘-MD’ except mention only user header fles, not system header fles.
 */
