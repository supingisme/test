#include<iostream>
#include<string>

using namespace std;

namespace rt{
    
    int r = 100;
    int t = 200;
};

using namespace rt;

int main(int argc, char *argv[])
{
    rt::r = 98;
    int r = 99;
    cout<<rt::r<<r<<endl;
    
    return 1;
}