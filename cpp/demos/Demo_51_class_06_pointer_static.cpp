#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class A{
    
public:
    static int a;
    static int f(){cout<<"f"<<endl;}
private:

};

int A::a = 10;

int main(int argc, char *argv[])
{
    A aa = A();
    aa.f();
    
    int *a = &A::a;
    cout<<*a<<endl;
    
    //静态类成员函数不能使用指针？？！！
    //int (A::*ff)() = &A::f;
    //(aa.*ff)();
    
    return 1;
}
