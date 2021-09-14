#include <stdlib.h>
#include <malloc.h>

int main()
{
    char *str;
    int ret = posix_memalign((void**)&str, 8, getpagesize());

    printf("ret = %d\n", ret);

    free(str);

}
