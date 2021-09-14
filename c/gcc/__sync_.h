/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:09 CST. */
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

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/*
 *	6.49 Built-in functions for atomic memory access
 *	The following builtins are intended to be compatible with those described in the Intel
 *	Itanium Processor-specifc Application Binary Interface, section 7.4. As such, they depart
 *	from the normal GCC practice of using the “ builtin ” prefx, and further that they are
 *	overloaded such that they work on multiple types.
 *	The defnition given in the Intel documentation allows only for the use of the types int,
 *	long, long long as well as their unsigned counterparts. GCC will allow any integral scalar
 *	or pointer type that is 1, 2, 4 or 8 bytes in length.
 *	Not all operations are supported by all target processors. If a particular operation cannot
 *	be implemented on the target processor, a warning will be generated and a call an external
 *	function will be generated. The external function will carry the same name as the builtin,
 *	with an additional sufx ‘_n’ where n is the size of the data type.
 *	In most cases, these builtins are considered a full barrier. That is, no memory operand
 *	will be moved across the operation, either forward or backward. Further, instructions will
 *	be issued as necessary to prevent the processor from speculating loads across the operation
 *	and from queuing stores after the operation.
 *	All of the routines are described in the Intel documentation to take “an optional list of
 *	variables protected by the memory barrier”. It’s not clear what is meant by that; it could
 *	mean that only the following variables are protected, or it could mean that these variables
 *	should in addition be protected. At present GCC ignores this list and protects all variables
 *	which are globally accessible. If in the future we make some use of this list, an empty list
 *	will continue to mean all globally accessible variables.
 *	type __sync_fetch_and_add (type *ptr, type value, ...)
 *	type __sync_fetch_and_sub (type *ptr, type value, ...)
 *	type __sync_fetch_and_or (type *ptr, type value, ...)
 *	type __sync_fetch_and_and (type *ptr, type value, ...)
 *	type __sync_fetch_and_xor (type *ptr, type value, ...)
 *	type __sync_fetch_and_nand (type *ptr, type value, ...)
 *	These builtins perform the operation suggested by the name, and returns the
 *	value that had previously been in memory. That is,
 *	{ tmp = *ptr; *ptr op= value; return tmp; }
 *	{ tmp = *ptr; *ptr = ~(tmp & value); return tmp; } // nand
 *	Note: GCC 4.4 and later implement __sync_fetch_and_nand builtin as *ptr
 *	= ~(tmp & value) instead of *ptr = ~tmp & value.
 *	type __sync_add_and_fetch (type *ptr, type value, ...)
 *	type __sync_sub_and_fetch (type *ptr, type value, ...)
 *	type __sync_or_and_fetch (type *ptr, type value, ...)
 *	type __sync_and_and_fetch (type *ptr, type value, ...)
 *	type __sync_xor_and_fetch (type *ptr, type value, ...)
 *	type __sync_nand_and_fetch (type *ptr, type value, ...)
 *	These builtins perform the operation suggested by the name, and return the
 *	new value. That is,
 *	{ *ptr op= value; return *ptr; }
 *	{ *ptr = ~(*ptr & value); return *ptr; } // nand
 *	Note: GCC 4.4 and later implement __sync_nand_and_fetch builtin as *ptr
 *	= ~(*ptr & value) instead of *ptr = ~*ptr & value.
 *	bool __sync_bool_compare_and_swap (type *ptr, type oldval type newval, ...)
 *	type __sync_val_compare_and_swap (type *ptr, type oldval type newval, ...)
 *	These builtins perform an atomic compare and swap. That is, if the current
 *	value of *ptr is oldval, then write newval into *ptr.
 *	The “bool” version returns true if the comparison is successful and newval was
 *	written. The “val” version returns the contents of *ptr before the operation.
 *	__sync_synchronize (...)
 *	This builtin issues a full memory barrier.
 *	type __sync_lock_test_and_set (type *ptr, type value, ...)
 *	This builtin, as described by Intel, is not a traditional test-and-set operation,
 *	but rather an atomic exchange operation. It writes value into *ptr, and returns
 *	the previous contents of *ptr.
 *	Many targets have only minimal support for such locks, and do not support a
 *	full exchange operation. In this case, a target may support reduced functionality
 *	here by which the only valid value to store is the immediate constant 1. The
 *	exact value actually stored in *ptr is implementation defned.
 *	This builtin is not a full barrier, but rather an acquire barrier. This means
 *	that references after the builtin cannot move to (or be speculated to) before
 *	the builtin, but previous memory stores may not be globally visible yet, and
 *	previous memory loads may not yet be satisfed.
 *	void __sync_lock_release (type *ptr, ...)
 *	This builtin releases the lock acquired by __sync_lock_test_and_set. Nor
 *	mally this means writing the constant 0 to *ptr.
 *	This builtin is not a full barrier, but rather a release barrier. This means that
*	all previous memory stores are globally visible, and all previous memory loads
*	have been satisfed, but following memory reads are not prevented from being
*	speculated to before the barrier.
 */
