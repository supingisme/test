#include <stdio.h>
#include <stdint.h>

int main()
{
	uint64_t u64 = 1L;
	
	int i;
	for(i=0;i<64;i++)
	{
		uint64_t _u64 = u64<<i;
		printf("MASK64_%-2ld  = (%#018lx),\n", i+1, _u64);
	}
}
