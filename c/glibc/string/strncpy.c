#include <stdio.h>
#include <string.h>

int main()
{
	int a = 1;
	char s[4] = {0};
	int b = 2;

#ifdef NOTUSE_STRNCPY
	strcpy(s, "hello");
#else
	strncpy(s, "hello", sizeof(s));
#endif

	printf("a = %d\n", a);
	printf("s = %s\n", s);
	printf("b = %d\n", b);
}
