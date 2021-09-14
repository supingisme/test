/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:40 CST. */
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
 *	bison or any such program can arrange this by writing ‘#line’ directives into the output
 *	fle. ‘#line’ is a directive that specifes the original line number and source fle name for
 *	subsequent input in the current preprocessor input fle. ‘#line’ has three variants:
 *	#line linenum
 *	linenum is a non-negative decimal integer constant. It specifes the line number
 *	which should be reported for the following line of input. Subsequent lines are
 *	counted from linenum.
 *	#line linenum filename
 *	linenum is the same as for the frst form, and has the same eﬀect. In addition,
 *	flename is a string constant. The following line and all subsequent lines are
 *	reported to come from the fle it specifes, until something else happens to
 *	change that. flename is interpreted according to the normal rules for a string
 *	constant: backslash escapes are interpreted. This is diﬀerent from ‘#include’.
 *	Previous versions of CPP did not interpret escapes in ‘#line’; we have changed
 *	it because the standard requires they be interpreted, and most other compilers
 *	do.
 *	#line anything else
 *	anything else is checked for macro calls, which are expanded. The result should
 *	match one of the above two forms.
 *	‘#line’ directives alter the results of the __FILE__ and __LINE__ predefned macros
 *	from that point on. See Section 3.7.1 [Standard Predefned Macros], page 21. They do not
 *	have any eﬀect on ‘#include’’s idea of the directory containing the current fle. This is a
 *	change from GCC 2.95. Previously, a fle reading
 *	#line 1 "../src/gram.y"
 *	#include "gram.h"
 *	would search for ‘gram.h’ in ‘../src’, then the ‘-I’ chain; the directory containing the
 *	physical source fle would not be searched. In GCC 3.0 and later, the ‘#include’ is not
 *	aﬀected by the presence of a ‘#line’ referring to a diﬀerent directory.
 *	We made this change because the old behavior caused problems when generated source
 *	fles were transported between machines. For instance, it is common practice to ship gen
 *	erated parsers with a source release, so that people building the distribution do not need to
 *	have yacc or Bison installed. These fles frequently have ‘#line’ directives referring to the
 *	directory tree of the system where the distribution was created. If GCC tries to search for
 *	headers in those directories, the build is likely to fail.
 *	The new behavior can cause failures too, if the generated fle is not in the same directory
 *	as its source and it attempts to include a header which would be visible searching from the
 *	directory containing the source fle. However, this problem is easily solved with an additional
 *	‘-I’ switch on the command line. The failures caused by the old semantics could sometimes
 *	be corrected only by editing the generated fles, which is difcult and error-prone.
 */

#include <stdio.h>
#include <setjmp.h>

int main()
{
    int i = 10;
#line 12 "line123.c"
//#line 
    printf("%s:%d\n", __FILE__, __LINE__);
    printf("%s:%d\n", __FILE__, __LINE__);
//#error "Error"
    printf("%s:%s\n", __TIME__, __DATE__);

	if(0)
	{
#define _RongTao_
	}
#ifdef _RongTao_
	printf("rongtadsfasdfadsf\n");
#endif

#if defined(_linux__)
	printf("linux\n");
#endif

    return 0;
}
