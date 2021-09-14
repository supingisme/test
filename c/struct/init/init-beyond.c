#include <stdio.h>

#define N 10

//好牛逼的操作
struct {
	int id;
}entity[N] = {
	[0 ... N-1] = {10},
};

int main()
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d, %d\n", i, entity[i].id);
	}

	return 0;
}
