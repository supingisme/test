#include<iostream>
#include<string>

using namespace std;

void f(int a){cout<<"f1"<<endl;}
//void f(double a){cout<<"f2"<<endl;}//此函数产生歧义
void f(double a, double b = 3.14){cout<<"f3"<<endl;}
void f(string str){cout<<"f4"<<endl;}

int main(int argc, char *argv[])
{
    f(1);
    f(2.3);
    f(1, 2);
    
    return 1;
}
