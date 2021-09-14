#include <stdio.h>
#include <stddef.h>
#include <errno.h>

#ifndef PROGRAM_INVOCATION_X
#warning Please define PROGRAM_INVOCATION_X
#define PROGRAM_INVOCATION_X program_invocation_name
#endif

int main()
{
	printf("%s\n", PROGRAM_INVOCATION_X);
}
