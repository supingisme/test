#include <stdio.h>

typedef int (*fn)();

struct test {
    int i;
    long l;
    fn f;
};

int f1(){
    long I = 1;
    printf("f1: %p\n", __builtin_frame_address(0));
    printf("f1: %p\n", __builtin_frame_address(1));
    printf("f1: %p\n", __builtin_frame_address(2));
    printf("f1: %p\n", __builtin_frame_address(3));
}

struct test t1;

int F();

int main()
{
    printf("ma: %p\n", __builtin_frame_address(0));
    
    F();
    
    return 0;
}


int F()
{
    t1.i = 2;
    t1.l = 3;
    t1.f = f1;

    printf("t1: %p\n", &t1);
    printf("F : %p\n", __builtin_frame_address(0));
    
    t1.f();
    

    return 1;
}


