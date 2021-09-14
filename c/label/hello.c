#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, a=0;
	n = atoi(argv[1]);
	if (n==1)
		goto loop_1;
	else
		goto loop_end;

/**
 *	label后面不能直接进行参数定义
 */

loop_1:
	int *pa = &a;//错误：标号只能是语句的一部分，而声明并非语句
	a = n;

loop_end:
	printf("a = %d\n", a);

	return 0;
}
