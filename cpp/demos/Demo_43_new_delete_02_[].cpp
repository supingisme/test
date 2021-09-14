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
#include <memory> //auto_ptr

#include"extern.h"

using namespace std;

          /* *p[3]: ERROR */
void f(int (*p)[3], int col, int row, int val)
{
    p[col][row] = val;
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.19 */ 
{   
    int *pi = new int[1024];
    int (*pi1)[1024] = new int[3][1024];
    int **pi0 = new int[2][3];
    int *pi9[3] = new int[2][3];
    /*错误：数组必须为一个由花括号包围的初始值设定所初始化*/
    //int pi2[2][3] = new int[2][3];
    
    /*
    动态分配数组的主要好处是它的第一维不必是常量值即在编译时刻不需要知道维
    数就像局部域或全局域中的定义所引入的数组的维数一样
    */
    for ( register int index = 0; index < 1024; ++index )
        pi[ index ] = 0;

    int (*pi2)[ 3 ] = new int[ 2 ][ 3 ]; //ok

    pi2[1][2] = 10;
    //pi2[2][1] = 10;//error
    cout<<pi2[1][2]<<endl;
    f(pi2,1,2,99);
    cout<<pi2[1][2]<<endl;

    delete [] pi;
    delete [] pi2;
    delete [] pi1;

    const int *pci = new const int(1024);
    delete pci;

    return 0;
}

