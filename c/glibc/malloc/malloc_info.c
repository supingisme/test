#include <stdio.h>
#include <malloc.h>


static void print_mallinfo(){

    struct mallinfo mf1 = mallinfo();
    printf("mallinfo.arena      = %d.\n", mf1.arena);
    printf("mallinfo.ordblks    = %d.\n", mf1.ordblks);
    printf("mallinfo.smblks     = %d.\n", mf1.smblks);
    printf("mallinfo.hblks      = %d.\n", mf1.hblks);
    printf("mallinfo.hblkhd     = %d.\n", mf1.hblkhd);
    printf("mallinfo.usmblks    = %d.\n", mf1.usmblks);
    printf("mallinfo.fsmblks    = %d.\n", mf1.fsmblks);
    printf("mallinfo.uordblks   = %d.\n", mf1.uordblks);
    printf("mallinfo.fordblks   = %d.\n", mf1.fordblks);
    printf("mallinfo.keepcost   = %d.\n", mf1.keepcost);
}

int main()
{
    FILE *fp = fopen("malloc_info.xml", "w");

    char *p1 = malloc(1039);
    
    printf("------------------------------------------\n");
    print_mallinfo();
    
    printf("------------------------------------------\n");
    malloc_stats();
    
    printf("------------------------------------------\n");
    malloc_info(0, stderr);
    malloc_info(0, fp);
    
    free(p1);
    fclose(fp);
}


