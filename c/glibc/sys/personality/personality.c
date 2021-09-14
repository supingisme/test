#include <sys/personality.h>
#include <stdio.h>

int main()
{
    unsigned long persona;
    int ret = personality(persona);

    printf("ret = %d, persona = %#010x\n", ret, persona);
    
}

