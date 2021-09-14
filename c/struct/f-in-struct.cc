#include <stdio.h>

struct __t {
	int i;
	void print(char *string) {
		printf("%s\n", __func__);
	}
};


int main()
{
	struct __t T;
	T.print("rongtao\n");
	//print("rongtao\n");//作用于尚未声明
	printf("sizeof = %d\n", sizeof(struct __t));

	return 0;
}
