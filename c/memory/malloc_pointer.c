#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/msg.h>


void my_malloc1(unsigned int size, char *buf)
{
    buf = malloc(size);
}

void my_malloc2(unsigned int size, char **buf)
{
    *buf = malloc(size);
}

void* my_malloc3(unsigned int size)
{
    return malloc(size);
}

void my_malloc4(unsigned int size, unsigned long addr)
{
    void *buf = malloc(size);
    memcpy(&addr, buf, sizeof(addr));
}

int main()
{
    char *name = NULL;

//    my_malloc1(10, name);
//    my_malloc2(10, &name);
//    name = my_malloc3(10);
    unsigned long addr;
    printf("%ld\n", addr);
    
    my_malloc1(10, (void*)addr);

    name = (void*)addr;
    
    memcpy(name, "rongtao", 10);

    printf("name: %s\n", name);

//    char **ptr;
//    my_malloc1(10, *ptr);
//
//    memcpy(*ptr, "rongtao", 10);
//
//    printf("*ptr: %s\n", *ptr);

    
    return 0;
}

