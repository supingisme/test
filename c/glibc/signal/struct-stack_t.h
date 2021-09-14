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
/*
stack_t [Data Type]
    This structure describes a signal stack. It contains the following members:
    void *ss_sp
        This points to the base of the signal stack.
    size_t ss_size
        This is the size (in bytes) of the signal stack which ‘ss_sp’ points to. You
        should set this to however much space you allocated for the stack.
        There are two macros defned in ‘signal.h’ that you should use in cal
        culating this size:
            SIGSTKSZ This is the canonical size for a signal stack. It is judged to
                    be sufcient for normal uses.
            MINSIGSTKSZ
                This is the amount of signal stack space the operating system
                needs just to implement signal delivery. The size of a signal
                stack must be greater than this.
                For most cases, just using SIGSTKSZ for ss_size is sufcient.
                But if you know how much stack space your program’s signal
                handlers will need, you may want to use a diﬀerent size. In
                this case, you should allocate MINSIGSTKSZ additional bytes
                for the signal stack and increase ss_size accordingly.
    int ss_flags
        This feld contains the bitwise or of these ﬂags:
        SS_DISABLE
            This tells the system that it should not use the signal stack.
        SS_ONSTACK
            This is set by the system, and indicates that the signal stack
            is currently in use. If this bit is not set, then signals will be
            delivered on the normal user stack.

*/

struct stack_t {
    void *ss_sp;
    size_t ss_size;
    int ss_flags;
};