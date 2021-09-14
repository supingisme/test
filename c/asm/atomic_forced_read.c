#include <stdio.h>

#ifndef atomic_forced_read/*    [rongtao comment 2019.10.24]*/
# define atomic_forced_read(x) \
	  ({ __typeof (x) __x; __asm ("" : "=r" (__x) : "0" (x)); __x; })
#endif

int main()
{
	int a = 10;

	printf("%d\n", atomic_forced_read(a));

	return 0;
}
