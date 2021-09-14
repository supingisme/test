#include <malloc.h>

static void print_mallinfo(){

    struct mallinfo mf1 = mallinfo();
    printf("------------------------------------------\n");
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
//struct mallinfo {
//   int arena;     /* Non-mmapped space allocated (bytes) */
//   int ordblks;   /* Number of free chunks */
//   int smblks;    /* Number of free fastbin blocks */
//   int hblks;     /* Number of mmapped regions */
//   int hblkhd;    /* Space allocated in mmapped regions (bytes) */
//   int usmblks;   /* Maximum total allocated space (bytes) */
//   int fsmblks;   /* Space in freed fastbin blocks (bytes) */
//   int uordblks;  /* Total allocated space (bytes) */
//   int fordblks;  /* Total free space (bytes) */
//   int keepcost;  /* Top-most, releasable space (bytes) */
//};
}

int main()
{
    char *p1 = malloc(1024);
    print_mallinfo();
    char *p2 = malloc(2024);
    print_mallinfo();

    malloc_trim(0);
    
    print_mallinfo();
}

