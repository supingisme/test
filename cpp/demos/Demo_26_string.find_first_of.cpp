#include<iostream>
#include<string>

using namespace std;


int main(int argc, char*argv[])
/* Rong Tao 2018.03.14 */ 
{
    string numerics( "0123456789" );
    string name2( "r2dad6sfw4" );
    string::size_type pos2 = name2.find_first_of( numerics );
    cout << "found numeric at index: " << pos2 << "\telement is "<< name2[pos2] << endl;

    while (( pos2 = name2.find_first_of( numerics, pos2 )) != string::npos )
    {
        cout << "11found numeric at index: "
            << pos2 << "\telement is "
            << name2[pos2] << endl;
        // 移到被找到元素的后一位置
        ++pos2;
    }


    return 0;
}

