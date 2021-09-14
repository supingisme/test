#include<iostream>
#include<string>

using namespace std;

void print(string str)
{
    cout<<str<<endl;
}
void print(string str1, string str2)
{
    cout<<str1<<str2<<endl;
}

int main(int argc, char *argv[])
{
    //函数指针根据指针的定义的参数列表和返回值决定指向哪个函数
    void (*p)(string) = &print;
    
    p(string("rong"));
    
    return 1;
}
