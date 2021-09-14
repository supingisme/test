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

void f() {
    int i;
    string str = "dwarves";
    int *pi = &i;
    short *ps = 0;
    double *pd = new double(33);
    //delete str; // 糟糕: "dwarves" 不是动态对象
    //delete pi; // 糟糕: pi 指向i, 一个局部对象
    delete ps; // 安全
    delete pd; // 安全
}
/*
下面三个常见程序错误都与动态内存分配有关
1 应用delete 表达式失败使内存无法返回空闲存储区这被称作内存泄漏memory leak
2 对同一内存区应用了两次delete 表达式这通常发生在两个指针指向同一个动态分配
    对象的时候这是一个很难踉踪的问题若多个指针指向同一个对象当通过某一个指针释
    放了该对象时就会发生这样的情况此时该对象的内存被返回给空闲存储区然后又被分
    配给某个别的对象接着指向旧对象的第二个指针被释放新对象也就跟着消失了
3 在对象被释放后读写该对象这常常会发生因为delete 表达式应用的指针没有被设置为0
*/
int main(int argc, char*argv[])
/* Rong Tao 2018.03.19 */ 
{   
    int *pi = new int(10);

    cout<<(*pi)<<endl;

    /* delete 表达式只能应用在指向的内存是用new 表达式从空闲存储区分配的指针上 */
    delete pi;
    //delete pi;//can't be twice

    cout<<(*pi)<<endl;

    return 0;
}

