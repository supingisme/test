#include <stdio.h>
#include <stdint.h>



/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note *//*   <rongtao 2019.10.11>*/
#ifndef _ASM_X86_SWAB_H
#define _ASM_X86_SWAB_H


static inline __attribute__((const)) uint32_t __linux_arch_swab32(uint32_t val)/*   <rongtao 2019.10.11>*/
{
	asm("bswapl %0" : "=r" (val) : "0" (val));
	return val;
}
#define __linux_arch_swab32 __linux_arch_swab32

static inline __attribute__((const)) uint64_t __linux_arch_swab64(uint64_t val)/*   <rongtao 2019.10.11>*/
{
#ifdef __i386__
	union {
		struct {
			uint32_t a;
			uint32_t b;
		} s;
		uint64_t u;
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
#define __linux_arch_swab64 __linux_arch_swab64

#endif /* _ASM_X86_SWAB_H */




int main()
{
	uint64_t u64 = 0x1234567890000000;
	uint32_t u32 = 0x12345678;

	printf("32: %x-%x\n", u32, __linux_arch_swab32(u32));
	printf("64: %lx-%lx\n", u64, __linux_arch_swab64(u64));

	return 0;
}
