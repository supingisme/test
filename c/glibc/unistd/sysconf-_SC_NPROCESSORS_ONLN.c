#include <stdio.h>
#include <unistd.h>

int main()
{
	//获取核心数
	printf("cores number = %d\n", sysconf(_SC_NPROCESSORS_ONLN));
}
