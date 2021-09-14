#include <stdio.h>

typedef int (*hello_t)();
typedef struct {
	int te;
	hello_t fn;
}text_t;

int helloworld() {
	printf("frame0 %p\n", __builtin_frame_address(0));
	printf("frame1 %p\n", __builtin_frame_address(1));

	hello_t fn = __builtin_frame_address(1);
	fn();
	return 0;
}


text_t T1 = {1, helloworld};
text_t T2 = {2, helloworld};

int main()
{
	T1.fn();
	T2.fn();

	return 1;
}
