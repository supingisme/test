#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

int main()
{
	syscall(SYS_memfd_create, "memfd_name", MFD_ALL_FLAGS);


	return 0;
}

