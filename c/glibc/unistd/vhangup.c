

#include <unistd.h>
#include <stdio.h>



int main()
{
    
    int ret = vhangup();
    printf("ret = %d\n", ret);
}


