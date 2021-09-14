#include <stdio.h>
#include "cpu_occupy.h"

int display(int cpuid, const struct core_occupy *occ, void *arg)
{     
    char *buffer = (char*)arg;
    sprintf(buffer, "%scpu%d \t%3d.%-4d %%\n", buffer,cpuid,occ->occupy.integer, occ->occupy.decimal);
}

int main()
{
    char buffer[1024] = {0};
    
    cpu_cores_occupy_chk_init();
    
    while(1) {
        sleep(1);
        
        cpu_cores_occupy_chk_display(display, buffer);
        
        system("clear");

        printf("%s", buffer);
    }
}

