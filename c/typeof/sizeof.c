#include <stdio.h>
#include <stdlib.h>

struct A {
	int id;	
	long int li;
};

struct B {
	struct A a[10];
	int i[10];
	int I;
};

int main()
{
	struct B b;

	printf("%d\n", sizeof(b.a));
	printf("%d\n", sizeof(b.i));

    char *c; 
    long *l;
    printf("sizeof c = %d\n", sizeof(c));
    printf("sizeof *c = %d\n", sizeof(*c));
    printf("sizeof l = %d\n", sizeof(l));
    printf("sizeof *l = %d\n", sizeof(*l));

	return 0;
}
