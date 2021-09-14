/* Rong Tao 2018.02.05 */
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstddef> /*size_t*/
#include<bitset>
using namespace std;

int main(int argc, char*argv[])
{
    int i = 1024;

    i |= 1<<15;

    cout<<hex<<i<<endl; //输出十六进制数
    cout<<oct<<i<<endl; //输出八进制数
    cout<<dec<<i<<endl; //输出十进制数
    cout<<bitset<32>(i)<<endl; //输出二进制数 error
    cout<<bitset<sizeof(int)*8>(i)<<endl; //输出二进制数
    cout<<bitset<sizeof(int)*4>(i)<<endl; //输出二进制数

    bitset<10> bit(0xf);//0x 十六进制标志

    bit[3] = 1;
    bit[6] = 1;
    cout<<bit<<endl;

    cout<<bit.test(3)<<endl;//pos 位是否为1
    cout<<bit.test(2)<<endl;//
    cout<<bit.any()<<endl;//任意位是否为1
    cout<<bit.none()<<endl;//是否没有位为1
    cout<<bit.count()<<endl;//值是1 的位的个数
    cout<<bit.size()<<endl;//位元素的个数
    cout<<bit[3]<<endl;//访问3 位
    cout<<bit.flip()<<endl;//翻转所有的位
    cout<<bit.flip(5)<<endl;//翻转5 位
    cout<<bit.set()<<endl;//将所有位置1
    cout<<bit.set(3)<<endl;//将3位置1
    cout<<bit.reset()<<endl;//将所有位置0
    cout<<bit.reset(3)<<endl;//将3位置0

    cout<<"string"<<bit.to_string()<<endl;

    bitset<12> bit2(012);
    cout<<bit2<<endl;

    string b("1010");
    bitset<12> bit3(b);
    cout<<bit3<<endl;

    b = "111111111100000000";
    bitset<12> bit4(b,6);
    cout<<bit4<<endl;
    
    cout<<bit4.to_string()<<endl;

    return 0;
}
