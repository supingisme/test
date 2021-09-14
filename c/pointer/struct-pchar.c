#include <stdio.h>
#include <stdlib.h>

typedef struct string_s {
	char *v;
}string;

void func(string *str, char *in)
{
	str->v=in;
}

int main()
{
	string str;

	func(&str, "rongtao");

	printf("string: %s\n", str.v);

	return 0;
}
