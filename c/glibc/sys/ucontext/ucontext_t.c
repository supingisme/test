#include <stdio.h>
#include <sys/ucontext.h>

int main()
{
#define S	sizeof(ucontext_t)
	printf("%d, %lx\n", S, S);
}
