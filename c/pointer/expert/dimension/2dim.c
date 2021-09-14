#include <stdio.h>
#include <stdlib.h>

char *sdoc[] = {
    "This is self document.",
    "Usage: two dimension",
    NULL,
};

void **alloc2(size_t size, int nx, int ny)
{
    void **ptr = NULL;
    ptr = (void**)malloc(sizeof(void*)*nx);
    int i;
    for(i=0;i<nx;i++)
        {
        ptr[i] = (void*)malloc(size*ny);
        }
    return ptr;
}

void free2(void **ptr, int nx)
{
    int i;
    for(i=0;i<nx;i++)
        {
        free(ptr[i]);
        }
    free(*ptr);
}

static void demo1()
{
    char **psdoc = sdoc;

    printf("%s\n", *(psdoc+1));
}
static void demo2()
{
    int **ptr = (int**)alloc2(sizeof(int), 3, 4);
    ptr[2][3] = 9;
    printf("%d\n", ptr[2][3]);

    free2((void**)ptr, 3);
    
    ptr[2][3] = 9;
    printf("%d\n", ptr[2][3]);
    //error, todo
}

#define printp(ptr) printf("\t%s \t%p \n", #ptr, ptr)
static void demo3()
{
    int **p = (int **)malloc(sizeof(int*)*3);
    int i;
    for(i=0;i<3;i++)
        p[i] = malloc(sizeof(int)*2);
    
    printp(p);
    printp(*p);

    printp(p[0]);
    printp(p[1]);
    printp(p[2]);
    
    printp(&p[0][0]);
    printp(&p[1][0]);
    printp(&p[2][0]);
    printp(&p[0][1]);
    printp(&p[1][1]);
    printp(&p[2][1]);

    int I[3][2];
    
    printp(I[0]);
    printp(I[1]);
    printp(I[2]);
    printp(&I[0][0]);
    printp(&I[1][0]);
    printp(&I[2][0]);
    printp(&I[0][1]);
    printp(&I[1][1]);
    printp(&I[2][1]);
    
}


int main()
{
    //demo1();
    //demo2();
    demo3();
    
}
