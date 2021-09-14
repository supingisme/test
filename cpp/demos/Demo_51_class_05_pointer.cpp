#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class A{
    
public:
    A(int cap)
        :_size(0), _cap(cap){_init();}

    int *a;
    static int ID;

    A& set(int tmp){a[_size++] = tmp; return *this;}
    A& get(){cout<<a[--_size]<<endl; return *this;}
    int getID(){return ID;}
private:
    int _size;
    int _cap;
    A& _init(){a = new int[_cap];}

};

int A::ID = 100;

int main(int argc, char *argv[])
{
    A a = A(3);
    
    a.set(10).get().set(23).get().set(1).set(2).get().get();
    
    //成员函数指针的定义
    int (A::*p1)() = &A::getID;
    
    //成员函数指针的调用:要有括号()
    cout<<(a.*p1)()<<endl;
    
    return 1;
}
