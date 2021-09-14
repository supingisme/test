#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = atoi(argv[1]);
	printf("0x%0x, %d\n", i, __builtin_clz(i));
}
