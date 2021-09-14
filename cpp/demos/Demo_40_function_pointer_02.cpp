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

typedef int (*F)(int);

int fun (int a){

    if(a>1)
        return fun(a-1)*a;
    else return 1;
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.17 */ 
{
    cout<<fun(5)<<endl;
    F f = fun;
    cout<<f(5)<<endl;

    return 0;
}

