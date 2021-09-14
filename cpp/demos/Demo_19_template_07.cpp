#include<iostream>
#include<string>

using namespace std;

template<class T>
void f(T t){ cout<<"1"<<endl;}

void f(int t){cout<<"2"<<endl;}

template <> void f<char>(char){cout<<"3"<<endl;}

int main(int argc, char *argv[])
{
    f<int>(3);
    f(3);
    f(3.4);
    f<int>(3.8);
    f('c');
    f<char>('e');
    return 1;
}
