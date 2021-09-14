#include <stdio.h>
#include <sys/types.h>
#include <asm/ldt.h> //struct user_desc

//int modify_ldt(int func, void *ptr, unsigned long bytecount);
//local descriptor table (ldt) 

int main()
{
    int ret;
    
    struct user_desc user_desc_in;
    struct user_desc ud[3];

    user_desc_in.entry_number = 2;
    user_desc_in.base_addr = (unsigned long)(&user_desc_in);
    
    ret = modify_ldt(1, &user_desc_in, sizeof(struct user_desc));
    printf("ret = %d\n", ret);

    
    ret = modify_ldt(0, ud, sizeof(struct user_desc)*3);
    printf("ret = %d\n", ret);
    printf("entry_number = %d\n", ud[0].entry_number);
    printf("entry_number = %d\n", ud[1].entry_number);
//    printf("base_addr = %p\n", (char*)ud.base_addr);
    
}
