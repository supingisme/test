#include <stdio.h>

//[root@localhost mcheck]# export MALLOC_CHECK_=1
//[root@localhost mcheck]# ./a.out 
//*ptr=mcheck test
//*** Error in `./a.out': free(): invalid pointer: 0x00000000025ef010 ***
//process end
//[root@localhost mcheck]# export MALLOC_CHECK_=2
//[root@localhost mcheck]# ./a.out 
//*ptr=mcheck test
//已放弃(吐核)
//[root@localhost mcheck]# 


int main(int argc, char * argv[])
{
    const char * src = "mcheck test";
    char * ptr = (char *)malloc(sizeof(char) * 32);
    memcpy(ptr, src, strlen(src));
    ptr[32] = '\0';  // 这里在堆内存块尾部越界
    printf("*ptr=%s\n", ptr);
        
    free(ptr);
    ptr = NULL;
    printf("process end\n");
 
    return 0;
}

