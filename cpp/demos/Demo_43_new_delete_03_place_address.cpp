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
#include <new> //new (place_address) type -specifier

#include"extern.h"

using namespace std;

const int chunk = 16;
class Foo {
public:
    int val() { return _val; }
    Foo() { _val = 0; }
private:
    int _val;
};
// 预分配内存但没有Foo 对象
char *buf = new char[ sizeof(Foo) * chunk ];

class A{};
char *p = new char[sizeof(A) * 10];//预分配内存但没有A对象

int main(int argc, char*argv[])
/* Rong Tao 2018.03.19 */ 
{   
    A *a = new(p)A;//在开辟的内存中创建对象
    delete[] p;
    // 在buf 中创建一个Foo 对象
    Foo *pb = new (buf) Foo;
    // 检查一个对象是否被放在buf 中
    if ( pb->val() == 0 )
        cout << "new expression worked!" << endl;
    // 到这里不能再使用 pb
    delete[] buf;

    return 0;
}

