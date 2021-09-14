#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <stdio.h>

int main ()
{
    gid_t list[3];
    
    int ret = getgroups(3, list);
    
    printf("list[0]=%d\n", list[0]);
    printf("list[1]=%d\n", list[1]);
    printf("list[1]=%d\n", list[1]);
}
