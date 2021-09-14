#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>
using namespace std;

int pow(int a, int b)
{
    if(b<1)
        return 1;
    else
        return a*pow(a,b-1);
}

int main(int argc, char*argv[])
{

    cout<<pow(2,5)<<endl;

    int a(10);
    string str("rongtao");
    str += " woshinidaye";
    cout<<a<<str<<endl;

    int (*f)(int, int);
    f = &pow;

    if(!str.empty())
        cout<<f(2,2)
            <<",\n"
            <<str.size()
            <<endl;

    const char p1 = ',';
    const char *p2 = ", ";
    string s1 = "rong";
    string s2("tao\n");
    string s3 = s1 + p1 + s2;
    string s4 = s1 + p2 + s2;

    #pragma message("error: C++ 不能将‘std::string’转换为‘char*’")
    //char *p3 = s4;

    cout<<s1
        <<s2
        <<__LINE__
        <<s3
        <<s4
        <<endl;   

    /* "replace": #include<algorithm> */
    replace( s4.begin(), s4.end(), 'r', '_' );
    cout<<s4
        <<endl; 

    return 0;
}
