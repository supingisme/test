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
#include"extern.h"

using namespace std;

void f(){
    /*
    当一个局部变量的值必须在多个函数调用之间保持有效时我们不能使用普
    通的自动对象自动对象的值在函数结束时被丢弃
    初始化只在f()首次被调用时执行一次;
    未经初始化的静态局部对象会被程序自动初始化为0;
    */
    static int a;
    a++;
    cout<<a<<endl;
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.19 */ 
{   
    f();
    f();
/*
$ make
g++ Demo.cpp  -w
./a.out
2
3
*/

    return 0;
}

