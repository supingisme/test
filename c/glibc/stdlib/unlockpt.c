#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int main()
{
	int fd = open("/dev/ptmx", 0x1111);
    
    if (unlockpt(fd) < 0)
        printf("Unable to unlockpt: %m");
    if (grantpt(fd) < 0)
        printf("Unable to grantpt: %m");
    
	return 0;
}

