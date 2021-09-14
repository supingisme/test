#include <stdio.h>

struct cell{
	enum type {virtual = 0x11, simulate} type;
};

int main()
{	
	struct cell cell;

	enum type type = simulate;

	cell.type = virtual;

	printf("type = %d, %d\n", cell.type, type);

	return 0;
}
