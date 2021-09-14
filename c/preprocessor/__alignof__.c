#include <stdio.h>

struct a {
	int id;
	char c1;
	long l1;
};

int main()
{
	printf("__alignof__ = %d\n", __alignof__(struct a));
}
