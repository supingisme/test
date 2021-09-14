#include <unistd.h>
#include <linux/sysctl.h>
#include <stdio.h>

int main()
{
    struct __sysctl_args args;

    //Glibc  does  not  provide  a wrapper for this system call; call it using syscall(2).
    int ret = _sysctl(&args);

    
}

