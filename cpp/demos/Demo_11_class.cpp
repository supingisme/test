/* Rong Tao 2018.1.16 */
#include<iostream>

using namespace std;

class A{

public:
    int a;
    
    void set(int tmp){
        a = tmp;
        cout<<"set"<<endl;
    } 

};
class B 
{
public:
    int b;
    void foo();
    void get(int);
    void put();
private:
    int c;
    
};

void B::foo()
{
    cout<<"B::foo"<<endl;
    c = 10;
}
void B::get(int tmp)
{
    c = tmp;
}
void B::put()
{
    cout<<c<<endl;
}
int main(int argc, char*argv[])
{
    A a;
    a.set(12);
    cout<<a.a<<endl;

    B b;
    b.foo();
    b.get(99);
    b.put();
    
    return 0;
}
