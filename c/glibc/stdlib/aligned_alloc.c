#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{
    char *str = (char*)aligned_alloc(8, getpagesize());

    strcpy(str, "helloadfasdf");
    printf("str = %s\n", str);

    free(str);

}

