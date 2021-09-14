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
/*
 *	6.5 Constructing Function Calls
 *	Using the built-in functions described below, you can record the arguments a function
 *	received, and call another function with the same arguments, without knowing the number
 *	or types of the arguments.
 *	You can also record the return value of that function call, and later return that value,
 *	without knowing what data type the function tried to return (as long as your caller expects
 *	that data type).
 *	However, these built-in functions may interact badly with some sophisticated features or
 *	other extensions of the language. It is, therefore, not recommended to use them outside
 *	very simple functions acting as mere forwarders for their arguments.
 *	void * __builtin_apply_args () [Built-in Function]
 *	This built-in function returns a pointer to data describing how to perform a call with
 *	the same arguments as were passed to the current function.
 *	The function saves the arg pointer register, structure value address, and all registers
 *	that might be used to pass arguments to a function into a block of memory allocated
 *	on the stack. Then it returns the address of that block.
 *	void * __builtin_apply (void (*function)(), void [Built-in Function]
 *	*arguments, size t size)
 *	This built-in function invokes function with a copy of the parameters described by
 *	arguments and size.
 *	The value of arguments should be the value returned by __builtin_apply_args.
 *	The argument size specifes the size of the stack argument data, in bytes.
 *	This function returns a pointer to data describing how to return whatever value was
 *	returned by function. The data is saved in a block of memory allocated on the stack.
 *	It is not always simple to compute the proper value for size. The value is used by
 *	__builtin_apply to compute the amount of data that should be pushed on the stack
 *	and copied from the incoming argument area.
 *	void __builtin_return (void *result) [Built-in Function]
 *	This built-in function returns the value described by result from the containing func
 *	tion. You should specify, for result, a value returned by __builtin_apply.
 *	__builtin_va_arg_pack () [Built-in Function]
 *	This built-in function represents all anonymous arguments of an inline function. It
 *	can be used only in inline functions which will be always inlined, never compiled
 *	as a separate function, such as those using __attribute__ ((__always_inline__
 *	)) or __attribute__ ((__gnu_inline__)) extern inline functions. It must be only
 *	passed as last argument to some other function with variable arguments. This is
 *	useful for writing small wrapper inlines for variable argument functions, when using
 *	preprocessor macros is undesirable. For example:
 *	extern int myprintf (FILE *f, const char *format, ...);
 *	extern inline __attribute__ ((__gnu_inline__)) int
 *	myprintf (FILE *f, const char *format, ...)
 *	{
 *	int r = fprintf (f, "myprintf: ");
 *	if (r < 0)
 *	return r;
 *	int s = fprintf (f, format, __builtin_va_arg_pack ());
 *	if (s < 0)
 *	return s;
 *	return r + s;
 *	}
 *	__builtin_va_arg_pack_len () [Built-in Function]
 *	This built-in function returns the number of anonymous arguments of an inline func
 *	tion. It can be used only in inline functions which will be always inlined, never
 *	compiled as a separate function, such as those using __attribute__ ((__always_
 *	inline__)) or __attribute__ ((__gnu_inline__)) extern inline functions. For
 *	example following will do link or runtime checking of open arguments for optimized
 *	code:
 *	#ifdef __OPTIMIZE__
 *	extern inline __attribute__((__gnu_inline__)) int
 *	myopen (const char *path, int oflag, ...)
 *	{
 *	if (__builtin_va_arg_pack_len () > 1)
 *	warn_open_too_many_arguments ();
 *	if (__builtin_constant_p (oflag))
 *	{
 *	if ((oflag & O_CREAT) != 0 && __builtin_va_arg_pack_len () < 1)
 *	{
 *	warn_open_missing_mode ();
 *	return __open_2 (path, oflag);
 *	}
*	return open (path, oflag, __builtin_va_arg_pack ());
*	}
*	if (__builtin_va_arg_pack_len () < 1)
	*	return __open_2 (path, oflag);
	*	return open (path, oflag, __builtin_va_arg_pack ());
	*	}
	*	#endif
 */
