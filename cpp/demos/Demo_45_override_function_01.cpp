#include<iostream>
#include<string>

using namespace std;

/**
如一个声明为局部的函数将隐
藏而不是重载一个全局域中声明的函数例如
*/

void print( const string & );
void print( double ); // overloads print()

int main(int argc, char *argv[])
{
    int ival = 99;
    // 独立的域隐藏print()的两个实例
    extern void print( int );
    // 错误: print( const string & )在这个域中被隐藏
    //print( "Value : " );
    print( ival ); // ok: print( int ) 可见
    
    return 1;
}
