#include <stdio.h>

#if __GNUC_PREREQ (2,96)
# define _pure __attribute__ ((__pure__))
#else
# define _pure
#endif

//这个函数这个函数没有副作用，当不需要它的返回值时，它可以被优化掉，
int _pure func1()
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
