#include <stdio.h>

/* 编译时会打印 不建议使用 的信息，告知哦程序员这是一个过时的接口  */
#define __deprecated  __attribute__((deprecated))

__deprecated void print_something()
{
	printf("print_something.\n");
}

int main()
{
	print_something();
}
