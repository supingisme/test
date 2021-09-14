#include <stdio.h>

//__attribute__((constructor))应该是在main函数之前,执行一个函数,便于我们做一些准备工作.

static  __attribute__((constructor(101))) void before1()
{
	    
	    printf("before1\n");
}
static  __attribute__((constructor(102))) void before2()
{
	    
	    printf("before2\n");
}
static  __attribute__((constructor(102))) void before3()
{
	    
	    printf("before3\n");
}

int main()
{
	printf("Main\n");
}
