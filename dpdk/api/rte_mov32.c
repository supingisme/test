#include <stdio.h>
#include <stdint.h>

static inline void
rte_mov32(uint8_t *dst, const uint8_t *src)
{
	asm volatile (
		"vld1.8 {d0-d3}, [%0]\n\t"
		"vst1.8 {d0-d3}, [%1]\n\t"
		: "+r" (src), "+r" (dst)
		: : "memory", "d0", "d1", "d2", "d3");
}

int main()
{
	uint8_t a = 10, b = 9;

	printf("a = %d, b = %d\n", a, b);

	rte_mov32(&a, &b);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}
