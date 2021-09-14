#include <stdio.h>

struct a{int id;};

int main()
{
	struct a a1 = {1};
	struct a a2 = a1;

	printf("a2.id = %d\n", a2.id);

	return 0;
}	
