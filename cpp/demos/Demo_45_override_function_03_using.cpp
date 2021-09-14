#include<iostream>
#include<string>

using namespace std;

namespace a
{
    void print(string str, string str2)
    {
        cout<<str<<str2<<endl;
    }
}
namespace b
{
    void print(string str)
    {
        cout<<"b:"<<str<<endl;
    }
}
void print(string str, int a)
{
    cout<<str<<endl;
}
int main(int argc, char *argv[])
{
    print(string("rong"), 99);
    
    using a::print;
    using b::print;
    
    print(string("rong"), string("tao"));
    print(string("rrrrr"));
    int a = 99;
    
    return 1;
}
