/* Rong Tao 2018.1.16 */
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>

using namespace std;


int main(int argc, char*argv[])
{
    int a = 10;
    /* 引用reference 有时候又称为别名alias 
        它可以用作对象的另一个名字通过引
        用我们可以间接地操纵对象使用方式类似于指针
        但是不需要指针的语法 */
    int &b = a; //b is "int", not "int*"
    int *c = &b;
    int &d = b;
    const int &e = d;
    const int &f = e;

    cout<<a
        <<b
        <<*c
        <<d
        <<e
        <<endl;

    b = 23;

    cout<<a
        <<b
        <<*c
        <<d
        <<e
        <<endl;

    return 0;
}
