#include <stdio.h>

typedef int (*fn_t)();

struct test {
	int i;
	fn_t fn;
};

struct test * gettest(){
	/** 求该算法的实现 
	 * 期望输出
	 *	Call t1's func.
	 *	Call t2's func.
	 */
}

int func() {
	struct test *t = gettest();
	switch(t->i) {
		case 1:	printf("Call t1's func.\n");break;
		case 2:	printf("Call t2's func.\n");break;
		default:printf("No this test entity.\n");break;
	}
	return 1;
}

int main() {
	struct test t1 = {1, func};
	struct test t2 = {2, func};
	t1.fn();
	t2.fn();
	return 0;
}





