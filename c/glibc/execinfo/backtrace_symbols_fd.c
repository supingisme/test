/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:11 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*	int backtrace (void **buffer, int size) [Function]
 *	The backtrace function obtains a backtrace for the current thread, as a list of point
 *	ers, and places the information into buﬀer. The argument size should be the number
 *	of void * elements that will ft into buﬀer. The return value is the actual number of
 *	entries of buﬀer that are obtained, and is at most size.
 *	The pointers placed in buﬀer are actually return addresses obtained by inspecting
 *	the stack, one return address per stack frame.
 *	Note that certain compiler optimizations may interfere with obtaining a valid back
 *	trace. Function inlining causes the inlined function to not have a stack frame; tail
 *	call optimization replaces one stack frame with another; frame pointer elimination
 *	will stop backtrace from interpreting the stack contents correctly.
 
 
 *	char ** backtrace_symbols (void *const *buffer, int size) [Function]
 *	The backtrace_symbols function translates the information obtained from the
 *	backtrace function into an array of strings. The argument buﬀer should be a
 *	pointer to an array of addresses obtained via the backtrace function, and size is the
 *	number of entries in that array (the return value of backtrace).
 *	The return value is a pointer to an array of strings, which has size entries just like
 *	the array buﬀer. Each string contains a printable representation of the corresponding
 *	element of buﬀer. It includes the function name (if this can be determined), an oﬀset
 *	into the function, and the actual return address (in hexadecimal).
 *	Currently, the function name and oﬀset only be obtained on systems that use the ELF
 *	binary format for programs and libraries. On other systems, only the hexadecimal
 *	return address will be present. Also, you may need to pass additional ﬂags to the
 *	linker to make the function names available to the program. (For example, on systems
 *	using GNU ld, you must pass (-rdynamic.)
 *	The return value of backtrace_symbols is a pointer obtained via the malloc function,
 *	and it is the responsibility of the caller to free that pointer. Note that only the return
 *	value need be freed, not the individual strings.
 *	The return value is NULL if sufcient memory for the strings cannot be obtained.
 
 
 *	void backtrace_symbols_fd (void *const *buffer, int size, int fd) [Function]
 *	The backtrace_symbols_fd function performs the same translation as the function
 *	backtrace_symbols function. Instead of returning the strings to the caller, it writes
 *	the strings to the fle descriptor fd, one per line. It does not use the malloc function,
 *	and can therefore be used in situations where that function might fail.
 */

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
/* Obtain a backtrace and print it to stdout. */
void print_trace (void)
{
	void *array[10];
	size_t size;
	char **strings;
	size_t i;
	size = backtrace (array, 10);
	strings = backtrace_symbols (array, size);
    
    
    FILE *fp = fopen("core.121212", "w");
    backtrace_symbols_fd (array, size, fileno(fp));
    fclose(fp);
    
	printf ("Obtained %zd stack frames.\n", size);
	for (i = 0; i < size; i++)
		printf ("%s\n", strings[i]);
    
	free (strings);
}
/* A dummy function to make the backtrace more interesting. */
void
dummy_function (void)
{
	print_trace ();
}

int
main (void)
{
	dummy_function ();
	return 0;
}
