#include <stdio.h>
#include <string.h>
#include <sys/types.h>

char *strcaseswap(char *str, ssize_t str_len) 
{
    char *c = str;
    while(*c){
        *c = (*c)&0xdf;
        c++;
    }
    return str;
}

int main()
{
    char str[] = {"AbasdADDadLJ"};
    printf("%s->%s\n", str, strcaseswap(str, strlen(str)));
}

