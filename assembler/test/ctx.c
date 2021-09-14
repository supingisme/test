/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 18:06:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:05 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:24:10 CST. */

#if defined(__x86_64__)
__asm__ (
".text\n"
".p2align 4,,15\n"
".globl ctx_switch\n"
".globl _ctx_switch\n"
"ctx_switch:\n"
"_ctx_switch:\n"
"	movq %rsp, 0(%rsi)	# save stack_pointer\n"
"	movq %rbp, 8(%rsi)	# save frame_pointer\n"
"	movq (%rsp), %rax	# save insn_pointer\n"
"	movq %rax, 16(%rsi)\n"
"	movq %rbx, 24(%rsi)\n	# save rbx,r12-r15\n"
"	movq 24(%rdi), %rbx\n"
"	movq %r15, 56(%rsi)\n"
"	movq %r14, 48(%rsi)\n"
"	movq 48(%rdi), %r14\n"
"	movq 56(%rdi), %r15\n"
"	movq %r13, 40(%rsi)\n"
"	movq %r12, 32(%rsi)\n"
"	movq 32(%rdi), %r12\n"
"	movq 40(%rdi), %r13\n"
"	movq 0(%rdi), %rsp	# restore stack_pointer\n"
"	movq 16(%rdi), %rax	# restore insn_pointer\n"
"	movq 8(%rdi), %rbp	# restore frame_pointer\n"
"	movq %rax, (%rsp)\n"
"	ret\n"
	);
#else
#pragma GCC error "__x86_64__ is not defined"
#endif
