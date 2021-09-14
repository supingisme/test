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

typedef int (*PFV)();
PFV test[10];

int (*test2[10])();

int t1(){};
int t2(){};
typedef int (*P)();
P t[2] = {
    t1,
    t2
};

typedef void (*PTR)();

void print1(){cout<<"print1\n";}
void print2(){cout<<"print2\n";}

int fun(string str, int *a)
{
    cout<<str<<(*a)<<endl;
}   

int main(int argc, char*argv[])
/* Rong Tao 2018.03.17 */ 
{
    int (*p) (string,int*);
    int a = 2;
    p = fun;
    (*p)(string("rong"),&a);

    p(string("tao"),&a);

    PTR ptr[2] = { print1, print2}; 
    (ptr)[0]();
    (ptr)[1]();
    
    
    return 0;
}

