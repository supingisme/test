#include<iostream>
#include<string>

using namespace std;


int main(int argc, char*argv[])
/* Rong Tao 2018.03.14 */ 
{
    string name( "12aAn naBelle" );
    int pos = name.find( "Anna" );
    if ( pos == string::npos )
        cout << "Anna not found!\n";
    else cout << "Anna found at pos: " << pos << endl;

    return 0;
}

/*
string::npos
npos的原型应该是std::container_type::size_type，
每一个容器类都会定义这个值，表示一个不存在的位，
用于统一对容器查找结果的判断，
如find函数，若没有找到相应的值，就会返回npos，
大家只要判断find返回的值是不是等于npos，
就能判断出，在该容器是不是存在该值，
平时我们判断的时候，只是看find返回的值是否等于-1，
若为-1则未找到，其实是因为string::pos为-1，故正确，
但是放在其他容器就不一定是这样，
故大家进行判断的时候最好用npos。
*/