#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

int main()
{
    int which;
    int who;
    
	int ret = syscall(SYS_ioprio_get, which, who);
    printf("0x%x\n", ret);

	return 0;
}

