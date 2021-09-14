#include <linux/futex.h>
#include <syscall.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    struct robust_list_head *head_ptr;
    size_t len_ptr;

    //*** demo.c:(.text+0x25)：对‘get_robust_list’未定义的引用 ***
    long ret = get_robust_list(getpid(), &head_ptr, &len_ptr);

    printf("len_ptr = %d\n", len_ptr);
}
