#include <stdio.h>

typedef int (*hello_t)();

int helloworld(hello_t hi) {
	printf("Hello World.\n");
}

hello_t hello=helloworld;

int main()
{
	hello();
	return 3;
}
