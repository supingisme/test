#include<iostream>
#include<string>

using namespace std;



int main(int argc, char*argv[])
/* Rong Tao 2018.03.14 */ 
{
    string str1("ronzasd");
    string str2("rontasd");
    cout<<str1.compare(str2)<<endl;
    cout<<str2.compare(str1)<<endl;
    

    return 0;
}

