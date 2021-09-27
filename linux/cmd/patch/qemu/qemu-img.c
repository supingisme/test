#include <stdio.h>

static int img_bench()
{
	hello_world();
	return 1234;
}

int main()
{
	int ret = 0;
	
	while(1) {
		img_bench();
		sleep(1);
	}

	return ret;
}
