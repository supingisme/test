#include <stdio.h>

struct align_test1 {
	int a;
	short b;
	int c;
}__attribute__((packed));

struct align_test2 {
	int a;
	short b;
unsigned :0;
	int c;
}__attribute__((packed));

int main()
{
	printf("align_test1 = %d\n", sizeof(struct align_test1));
	printf("align_test2 = %d\n", sizeof(struct align_test2));
	return 0;
}
