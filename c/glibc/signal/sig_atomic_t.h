/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
// 24.4.7.2 Atomic Types
// To avoid uncertainty about interrupting access to a variable, you can use a particular data
// type for which access is always atomic: sig_atomic_t. Reading and writing this data type
// is guaranteed to happen in a single instruction, so there’s no way for a handler to run “in
// the middle” of an access.
// The type sig_atomic_t is always an integer data type, but which one it is, and how
// many bits it contains, may vary from machine to machine.
// sig_atomic_t [Data Type]
// This is an integer data type. Objects of this type are always accessed atomically.
// In practice, you can assume that int is atomic. You can also assume that pointer
// types are atomic; that is very convenient. Both of these assumptions are true on all of the
// machines that the GNU C library supports and on all POSIX systems we know of.
// 24.4.7.3 Atomic Usage Patterns
// Certain patterns of access avoid any problem even if an access is interrupted. For example,
// a ﬂag which is set by the handler, and tested and cleared by the main program from time
// to time, is always safe even if access actually requires two instructions. To show that this
// is so, we must consider each access that could be interrupted, and show that there is no
// problem if it is interrupted.
// An interrupt in the middle of testing the ﬂag is safe because either it’s recognized to be
// nonzero, in which case the precise value doesn’t matter, or it will be seen to be nonzero the
// next time it’s tested.
// An interrupt in the middle of clearing the ﬂag is no problem because either the value
// ends up zero, which is what happens if a signal comes in just before the ﬂag is cleared, or
// the value ends up nonzero, and subsequent events occur as if the signal had come in just
// after the ﬂag was cleared. As long as the code handles both of these cases properly, it can
// also handle a signal in the middle of clearing the ﬂag. (This is an example of the sort of
// reasoning you need to do to fgure out whether non-atomic usage is safe.)
// Sometimes you can insure uninterrupted access to one object by protecting its use with
// another object, perhaps one whose type guarantees atomicity. See Section 24.4.5 [Signals
// Close Together Merge into One], page 622, for an example.