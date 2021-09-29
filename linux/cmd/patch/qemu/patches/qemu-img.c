#include <stdio.h>
#include <unistd.h>

int hello_world();
void test1();

static int img_bench()
{
	printf("img_bench be hacked.\n");
	hello_world();
	test1();
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
