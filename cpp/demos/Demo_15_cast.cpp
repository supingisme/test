#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstddef> /*size_t*/
#include<bitset>
/*
总体讲，利用带有_cast修饰的语句，消除了原有的一些特性（const）
*/
using namespace std;

int ival = 1024;
void *pv;
int *pi = &ival;
const char *pc = "a casting call";

int main(int argc, char*argv[])
/* Rong Tao 2018.02.05 */
{
    pv = pi;

    /*// 错误：从类型‘void*’到类型‘const char*’的转换无效*/
    //pc = pv;
    pc = static_cast<char*>(pv);

    char *p = new char[strlen(pc) + 1];
    strcpy(p,pc);

    cout<<pv<<endl;
    cout<<pi<<endl;
    cout<<pc<<endl;
    cout<<p<<endl;

    enum m{f=1,s,t};
    m mm = static_cast<m>(ival);
    cout<<mm<<endl;

    complex<int> *pcom;
    char *ppcom = reinterpret_cast<char*>(pcom);
    cout<<ppcom<<endl;

    void *pp;
    const char *s1 = "rongtao";
    char *s2 = "rongrong";
    pp = s2;
    cout<<s1<<endl;
    s1 = static_cast<char*>(pp);
    cout<<s1<<endl;
    if(s1)
        cout<<s1<<endl;
    else 
        cout<<"oooo"<<endl;
    
    return 0;
}
/*

static_cast 
const_cast 转换掉表达式的常量性以及volatile 对象的volatile性
dynamic_cast 
reinterpret_cast通常对于操作数的位模式执行一个比较低层次的重新解释

*/
