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
#include<cstdarg>
using namespace std;

inline void display(string str)
{
    cout<<"string: "<<str<<endl;
}
inline void display(int i)
{
    cout<<"int: "<<i<<endl;
}

/*如如果程序员想修改指针本身而不
是指针引用的对象那么他可以声明一个参数该参数是一个指针的引用*/
void ptrswap(int *&p1, int *&p2)
{
    int *tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void f1(int &a)
{
    cout<<a<<endl;
}

void f2(int a=1, int b=2, char c = 'c')
{
    cout<<a<<b<<c<<endl;
}

//void f3(int &a, int &b, int &c=2){};//error
/*
Demo.cpp:53: 错误：‘void f3(int, int, char)’的第 2 个形参缺少默认实参
Demo.cpp:53: 错误：‘void f3(int, int, char)’的第 3 个形参缺少默认实参

void f3(int a=1, int b,char c)
{
    cout<<a<<b<<c<<endl;
}
*/

int add(int num,...)  
//求和函数
{
    va_list args;
    int sum=0;
    va_start(args,num);
    for(int i=0;i<num;i++)
        sum += va_arg(args,int);      
    va_end(args);
    return sum;
}
int printf( const char* ... );

int & f5(int &a)
{
    int *b;
    b = &a;
    return *b;
}   

int &f6(int &a)
{
    return a;
}

void f7(int a, int b, char c='\n', int d=10)
/*只允许最后的几个省略*/
{
    cout<<"f7: "<<c<<a<<b<<d<<endl;
}

int main(int argc, char*argv[])
/* Rong Tao 2018.03.15 */ 
{
    cout<<"add: "<<add(6,2,3,4,5,6,0)<<endl;
    f7(23,35,'w');
    
    display("rong");
    display(1);
    display(3.14);

    int i = 10, j = 20;
    int *pi = &i, *pj = &j;
    cout<<*pi<<*pj<<endl;
    ptrswap(pi,pj);
    cout<<*pi<<*pj<<endl;
    
    //f1(10);//error
    f1(i);
    f2();
    f2(3,4);
    f2(3,'A');
    
    int a = f5(i);
    cout<<"a: "<<a<<endl;

    int b ;

    cout<<a<<endl;
    f6(a)++;
    cout<<a<<endl;


    return 0;
}

