#include <stdio.h>

#define _gcc_posion(v) #pragma GCC posion v

_gcc_posion(printf)

int main()
{
	

	return 0;
}
