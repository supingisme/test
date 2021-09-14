#include <stdio.h>
#include <stdlib.h>

#ifndef __swapbyte64
#define __swapbyte64(l64) (((l64>>56)&0xff)      | ((l64&0xff)<<56) |\
			                  ((l64>>40)&0xff00)     | ((l64&0xff00)<<40) |\
			                  ((l64>>24)&0xff0000)   | ((l64&0xff0000)<<24) |\
			                  ((l64>> 8)&0xff000000) | ((l64&0xff000000)<<8))
#endif

int main()
{
	unsigned long l = 0x40000000;

	printf("%lx -> %lx\n", l, __swapbyte64(l));

}
