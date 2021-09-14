#include <stdio.h>

struct _holder_info{
	enum _holder_type{READ, WRITE} _type;
	int READ;
};

int main()
{
	struct _holder_info info;
	info._type = READ;

	printf("info._type = %d\n", info._type);

	return 0;
}
