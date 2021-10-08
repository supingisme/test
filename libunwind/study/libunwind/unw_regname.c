#include <libunwind.h>
#include <stdio.h>

int main()
{
	int i;
	for(i=0; i<18; i++) {
		printf("i=%4d, %s\n", i, unw_regname(i));
	}
}
