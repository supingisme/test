#include <stdio.h>

union uptr {
    unsigned long l;
    void *p;
};

int main()
{
    union uptr uptr;
    int i =  1;
    uptr.p = &i;

    printf("%lx, %p\n", uptr.l, &i);
}
