#include <stdio.h>



int f1(){
    long I = 1;
    printf("f1: %p, %p\n", __builtin_return_address(0), &I);
    printf("f1: %p, %p\n", __builtin_return_address(1), &I);
    printf("f1: %p, %p\n", __builtin_return_address(2), &I);
    printf("f1: %p, %p\n", __builtin_return_address(3), &I);
}

int f2(){
    long I = 2;
    printf("f2: %p, %p\n", __builtin_return_address(0), &I);
    printf("f2: %p, %p\n", __builtin_return_address(1), &I);
    printf("f2: %p, %p\n", __builtin_return_address(2), &I);
//    printf("f2: %p, %p\n", FRAME(3), &I);
    return f1();
}

int f3(){
    long I = 3;
    printf("f3: %p, %p\n", __builtin_return_address(0), &I);
    printf("f3: %p, %p\n", __builtin_return_address(1), &I);
//    printf("f3: %p, %p\n", FRAME(2), &I);
//    printf("f3: %p, %p\n", FRAME(3), &I);
    return f2();
}


int main()
{
    long I = 4;
    printf("ma: %p, %p\n", __builtin_return_address(0), &I);
//    printf("ma: %p, %p\n", FRAME(1), &I);
    return f3();
}





