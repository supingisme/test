#include <stdio.h>

#include "pure.h"

//这个函数这个函数没有副作用，当不需要它的返回值时，它可以被优化掉，
int __attribute_pure__ func1()
{
	printf("func1 pure test.\n");
}

int func2()
{
	printf("func2 pure test.\n");
}

int main()
{
	func1();

	int a = func1();

	func2();

	return 0;
}
