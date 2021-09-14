#define WRITE_ONCE(var, val) \
	(*((volatile typeof(val) *)(&(var))) = (val))

#define READ_ONCE(var) (*((volatile typeof(var) *)(&(var))))


#include <stdio.h>

int main()
{
    int a= 1, b = 123;
    printf("a = %d\n", a);

    WRITE_ONCE(a, 12);

    printf("a = %d\n", a);
    
    a = READ_ONCE(b);
    
    printf("a = %d\n", a);

}

