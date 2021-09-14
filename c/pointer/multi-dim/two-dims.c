#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct a {
	int i;
};

void func(struct a *a)
{
	memset(&a, 0, sizeof(struct a));
}

int main()
{
	struct a a = {1};

	func(&a);

	printf("a.i = %d\n", a.i);

	return 0;
}
