#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <errno.h>

int main()
{
	syscall(SYS_delete_module, "mymod", O_NONBLOCK);


	return 0;
}


