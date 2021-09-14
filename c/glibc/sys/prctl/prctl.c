#include <sys/prctl.h>
#include <stdio.h>

//int prctl(int option, unsigned long arg2, unsigned long arg3,
//         unsigned long arg4, unsigned long arg5);

void pr_get_endian()
{
    //有问题啊
    int endian; 
    prctl(PR_GET_ENDIAN, &endian, 0,0,0);

    switch(endian) {
        case PR_ENDIAN_BIG:
            printf("PR_ENDIAN_BIG\n");
            break;
        case PR_ENDIAN_LITTLE://	1	/* True little endian mode */
            printf("PR_ENDIAN_LITTLE\n");
            break;
        case PR_ENDIAN_PPC_LITTLE://	2	
            printf("PR_ENDIAN_PPC_LITTLE\n");
            break;
        default:
            printf("unknown endian.%d\n", endian);
            break;
    }
}
void pr_get_procname()
{
    //有问题啊
    char name[123] = {0}; 
    prctl(PR_GET_NAME, name, 0,0,0);

    printf("name = %s\n", name);
}

int main()
{
    pr_get_endian();
    pr_get_procname();
}

