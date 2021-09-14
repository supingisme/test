#include <pthread.h>
#include <stdio.h>

__thread int t;

int main()
{
	int a = 10;

	t = a;

	return 0;
}
