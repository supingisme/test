#include <stdio.h>

#define debug() _print("\n")
#define info(fmt...)  _print(fmt)
#define _print(fmt...) \
    do{\
        fprintf(stdout, "%s:%d %s ", __FILE__, __LINE__, __func__);\
        fprintf(stdout, fmt);\
    }while(0)
    
#define show_ptr_addr(ptr) info("\t %s \t %p\n", #ptr, ptr)

static char note[] = {"1234567890"};
static char lines[2][64] = {"1234567890","abcdefghijk"};
static char *(plines[2]) = {"1234567890","abcdefghijk"};



static void demo1_2d_ptr()
{
    debug();

    void *p1 = note;
    show_ptr_addr(p1);
    
    void **pp1 = (void*)lines;
    show_ptr_addr(pp1);
    show_ptr_addr(*pp1);
    show_ptr_addr(lines);
    show_ptr_addr(lines[0]);
    show_ptr_addr(lines[1]);
    
    pp1 = (void*)plines;
    show_ptr_addr(pp1);
    show_ptr_addr(*pp1);
    show_ptr_addr(plines);
    show_ptr_addr(plines[0]);
    show_ptr_addr(plines[1]);
    
}


int main()
{
    demo1_2d_ptr();
}

