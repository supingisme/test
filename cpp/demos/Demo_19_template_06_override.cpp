#include<iostream>
#include<string>

using namespace std;

template < class type>
void foo(type t, int i)
{
    cout<<"1"<<endl;
}
template < class type>
void foo(type* t, int i)
{
    cout<<"2"<<endl;
}
template < class type, class type2>
void foo(type t, type2 i)
{
    cout<<"3"<<endl;
}

int main(int argc, char *argv[])
{
    int a = 9;
    
    foo<int>(2,3);
    foo<int*>(&a, 3);
    foo<int>(&a, 4);
    foo<int ,int>(3,4);
    foo(2, 8.0);
    foo(3, 4);
    
    return 1;
}
