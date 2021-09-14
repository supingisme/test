#include<iostream>
#include<string>

using namespace std;

namespace China_University_of_Petrolume{int a = 999;}

int main(int argc, char *argv[])
{
    namespace upc = China_University_of_Petrolume;
    
    cout<<upc::a<<endl;
    
    using China_University_of_Petrolume::a;
    
    cout<<a<<endl;
    return 1;
}
