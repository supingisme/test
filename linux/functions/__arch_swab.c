#include <stdio.h>
#include <stdint.h>

//#define __attribute_const__ __attribute__((const))
#define __u32 uint32_t
#define __u64 uint64_t


/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note *//*   <rongtao 2019.10.11>*/
#ifndef _ASM_X86_SWAB_H
#define _ASM_X86_SWAB_H

//#include <linux/types.h>
//#include <linux/compiler.h>

static inline __attribute_const__ __u32 __arch_swab32(__u32 val)/*   <rongtao 2019.10.11>*/
{
	asm("bswapl %0" : "=r" (val) : "0" (val));
	return val;
}
#define __arch_swab32 __arch_swab32

static inline __attribute_const__ __u64 __arch_swab64(__u64 val)/*   <rongtao 2019.10.11>*/
{
#ifdef __i386__
	union {
		struct {
			__u32 a;
			__u32 b;
		} s;
		__u64 u;
	} v;
	v.u = val;
	asm("bswapl %0 ; bswapl %1 ; xchgl %0,%1"
			: "=r" (v.s.a), "=r" (v.s.b)
			: "0" (v.s.a), "1" (v.s.b));
	return v.u;
#else /* __i386__ */
	asm("bswapq %0" : "=r" (val) : "0" (val));
	return val;
#endif
}
#define __arch_swab64 __arch_swab64

#endif /* _ASM_X86_SWAB_H */




int main()
{
	uint64_t u64 = 0x1234567890000000;
	uint32_t u32 = 0x12345678;

	printf("32: %x-%x\n", u32, __arch_swab32(u32));
	printf("64: %lx-%lx\n", u64, __arch_swab64(u64));

	return 0;
}
