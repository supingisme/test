#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstddef> /*size_t*/
#include<bitset>
#include<assert.h>
#include<cstdlib>//abort()
#include<list>
#include<map>
#include<deque>
#include<set>
#include<iterator>
#include<exception>
#include<stack>
#include<queue>

using namespace std;

/*
链接指示符 extern "C"
*/
extern "C" {

    int print(const char*);
}
extern "C" int scan(char *);

extern "C"{
    #include"Demo_38_extern.h"
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.17 */ 
{
    print("rong\n");

    char *a;
    scan(a);
    print(a);

    return 0;
}

