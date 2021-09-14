#include <stdio.h>

typedef int (*fn_t)();

struct text {
	int i;
	fn_t fn;
};

int hello(struct text *t) {
	return printf("Hello. %p\n", t);
}

struct text TEXT = {
	1,
	hello,
};

int main()
{
	printf("%p\n", &TEXT);
	
	TEXT.fn();

	return 0;
}
