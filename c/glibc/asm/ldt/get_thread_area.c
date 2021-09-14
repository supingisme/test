#include <linux/unistd.h>
#include <asm/ldt.h>
#include <stdio.h>

int main(){
    struct user_desc u_info;

    //get_thread_area - get a thread-local storage (TLS) area
    int ret = get_thread_area(&u_info);
    //get_thread_area.c:(.text+0x15)：对‘get_thread_area’未定义的引用
    
    //unsigned int  entry_number;
    //unsigned long base_addr;
    //unsigned int  limit;
    //unsigned int  seg_32bit:1;
    //unsigned int  contents:2;
    //unsigned int  read_exec_only:1;
    //unsigned int  limit_in_pages:1;
    //unsigned int  seg_not_present:1;
    //unsigned int  useable:1;

    printf("u_info.entry_number = %d\n", u_info.entry_number);
}
