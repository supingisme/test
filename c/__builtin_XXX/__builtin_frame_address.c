#include <stdio.h>

int f1();
int f2();

typedef int (*fn)();

fn F = NULL;

int main()
{
	printf("main: %p\n", main);
	f1();
}

int f1(){
	long I;
	printf("f1: %p, %p\n", f1, &I);
	return f2();
}

int f2(){
	long I = 12;
	printf("f2: %p\n", f2);
	printf("0: %p, %p\n", __builtin_frame_address(0), &I);
	//F = __builtin_frame_address(0);
	//F = f2;
	//F();
	printf("1: %p\n", __builtin_frame_address(1));
	printf("2: %p\n", __builtin_frame_address(2));
	printf("3: %p\n", __builtin_frame_address(3));
	printf("4: %p\n", __builtin_frame_address(4));

	return 0;
}


