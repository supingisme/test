#include <stdio.h>


int fun(char str[123])
{
	return printf("sizeof str = %d\n", sizeof(str));
}

int main()
{
	char a[] = {"rongtao"};
	fun(a);

	return 0;
}
