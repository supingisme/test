//strchr, strrchr, strchrnul - locate character in string

#include <string.h>

char *strchr(const char *s, int c);

char *strrchr(const char *s, int c);

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <string.h>

char *strchrnul(const char *s, int c);


//demo
#include <stdio.h>

int main()
{
	char *str = "rongtao zaima";
	printf("%s\n", strchr(str, 't'));

	return 0;
}
