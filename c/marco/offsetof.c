#include <stdio.h>
//#include "./offsetof.h"
#include "offsetof_raw.h"

//#define offsetof(type_, Member) ((size_t)&((type_*)0)->Member)
#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif
struct A{
	int id;
	int a;
};

int main()
{
#ifdef offsetof
	printf("%d\n", offsetof(struct A, a));
#endif

    struct test {
        int a;
        long b;
        int c;
    };

    int pos = offsetof(struct test, c);
    printf("pos = %d\n", pos);
}

