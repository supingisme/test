#include <sys/prctl.h>
#include <asm/prctl.h>

#include <stdio.h>
#include <errno.h>


int main()
{
    unsigned long addr;
    int ret = arch_prctl(ARCH_SET_FS, &addr);
    if(ret != 0){
        printf("error arch_prctl, ret = %d\n\n", ret);
    }

    switch(ret){
        case -EFAULT:
            printf("EFAULT addr points to an unmapped address or is outside the process address space.\n");
            break;
        case -EINVAL:
            printf("EINVAL code is not a valid subcommand.\n");
            break;
        case -EPERM:
            printf("EPERM  addr is outside the process address space.\n");
            break;
        default:
            printf("  success.\n");
            break;
    }
    
    printf("FS register addr:%ld\n", addr);

    //产生段错误
}


