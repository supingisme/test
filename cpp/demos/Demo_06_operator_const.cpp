#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class A{

public:

    bool operator == (const A&)const;
    bool operator != (const A&)const;

    A& operator = (const A&);


    int a;

    int size() const { return _size;}
    int size(int a) const { return a+_size;}

private:

    int _size;

};

int main(){

    A a0(1), a1(2);

    a0.a = 1;
    a1.a = 2;



}
