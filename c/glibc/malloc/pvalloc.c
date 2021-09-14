#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{
    char *str = (char*)pvalloc(getpagesize());

    strcpy(str, "helloadfasdf");
    printf("str = %s\n", str);

    free(str);

}



