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
        cout<<str<<endl;
    }
}

int main(int argc, char *argv[])
{
    using a::print;
    using b::print;
    
    print(string("rong"), string("tao"));
    print(string("rrrrr"));
    
    return 1;
}
