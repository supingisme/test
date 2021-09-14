#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    long double a[4], b[4], loadavg;
    FILE *fp;
    char dump[50];

    for(;;)
    {
        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
        fclose(fp);
        sleep(2);

        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        fclose(fp);

        //      user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice.

        //cpu  195044598 6619 410450970 967314001 64039 0 85058 394458 0 0
        //cpu0 48705507 1701 102480874 241499274 14130 0 82302 103069 0 0
        //cpu1 48866063 1895 102699462 241657644 15853 0 1245 97930 0 0
        //cpu2 48782413 1260 102714102 242031473 18001 0 790 96743 0 0
        //cpu3 48690614 1762 102556531 242125609 16054 0 720 96715 0 0
        //

        //张恒昊给出的计算公式
        //User	  nice  system    idle   iowait  irq softirq steal guest guest_nice
        //（user + nice + system）/（user + nice + system + idle + iowait + irq + softirq）*100%

        //程序中的这个公式
        loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
        printf("The current CPU utilization is : %Lf\n",loadavg);
    }
    
    return(0);
}

