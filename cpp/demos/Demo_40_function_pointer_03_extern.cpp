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

#include<ctype.h>//atoi()

using namespace std;

#include "extern.h"

#ifdef _CPP_C_
extern "C" int print(const char*);
#endif

int (*p)(const char *);

int main(int argc, char*argv[])
/* Rong Tao 2018.03.17 */ 
{   
    p = print;
    p("rong\n");

    return 0;
}

