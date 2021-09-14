#include <stdio.h>

typedef int (*fn_t)();

struct test {
	fn_t fn;
};

int func() {
	return printf("func called.\n");
};

struct test t = {func};

void main() {
//	t.fn = func;
	t.fn();
};
