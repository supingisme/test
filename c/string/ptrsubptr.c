#include <stdio.h>

size_t strsub(const char *s1, const char *s2)
{
	return s1-s2;
}

int main()
{
	char *str = "rongtao";
	char *p = &str[2];

	printf("%d\n", strsub(str, p));

	return 0;
}
