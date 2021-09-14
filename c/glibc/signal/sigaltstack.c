#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    stack_t oss;
    int ret = sigaltstack(NULL, &oss);
    printf("ret = %d\n", ret);

    
    printf("oss.ss_flags    = %d\n", oss.ss_flags);
    printf("oss.ss_size     = %ld\n", oss.ss_size);
    printf("oss.ss_sp       = %p\n", oss.ss_sp);

    if(SS_ONSTACK == oss.ss_flags)
        printf("The process is currently executing on the alternate signal stack.\n");

    if(SS_DISABLE == oss.ss_flags) //我的系统是这个
        printf("The alternate signal stack is currently disabled.\n");
    
    return 0;
}












