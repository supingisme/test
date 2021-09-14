#include<iostream>
#include<string>

using namespace std;

namespace rt{

    int r = 100;
    int t = 200;
    template <typename elemType>
    void print(elemType r, elemType t)
    {
        cout<<r<<t<<endl;
    }
    //嵌套namespace
    namespace R{
      
        int r = 10;
        int t = 20;
        void print()
        {
            cout<<"rt::r::"<<endl;
        }
        void print(string str);
    };
};
void rt::R::print(string str)
{
    cout<<"printtt: "<<str<<endl;
}
using namespace rt;

int main(int argc, char *argv[])
{
    rt::r = 98;
    int r = 99;
    cout<<rt::r<<r<<endl;
    rt::print<int>(rt::r, r);
    rt::print<string>(string("rong"), string("tao"));
    
    rt::R::print();
    rt::R::print("rongtaoshinidaye");
    return 1;
}
