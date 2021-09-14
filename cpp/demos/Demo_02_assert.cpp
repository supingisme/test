#include<iostream>
#include<assert.h>
#include<cassert>
using namespace std;


int main(){

    int a = 0;

/*
-bash-4.1$ ./a
a: Demo.cpp:11: int main(): Assertion `a == 1' failed.
已放弃 (core dumped)
*/
    assert(a == 1);

}
