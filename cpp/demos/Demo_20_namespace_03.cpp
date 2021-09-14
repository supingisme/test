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
};

using namespace rt;

int main(int argc, char *argv[])
{
    rt::r = 98;
    int r = 99;
    cout<<rt::r<<r<<endl;
    rt::print<int>(rt::r, r);
    rt::print<string>(string("rong"), string("tao"));
    return 1;
}
