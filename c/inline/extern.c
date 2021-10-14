#include <stdio.h>

extern inline int hello();
inline int hello()
{
	printf("hello\n");
}

int main()
{
	hello();
}
