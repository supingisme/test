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

inline int fun (int a)
{
    if(a>1){
        return fun(a-1)*a;
    }
   else 1;
}
/*
若一个函数被指定为inline 函数则它将在程
序中每个调用点上被内联地展开
*/
inline void fun2(int a)
{
    cout<<"rong: "<<a<<endl;
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.17 */ 
{
    cout<<fun(5)<<endl;
    fun2(3);
    return 0;
}

