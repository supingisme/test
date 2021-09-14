#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{
    char *str = (char*)valloc(getpagesize());

    strcpy(str, "helloadfasdf");
    printf("str = %s\n", str);

    free(str);

}


