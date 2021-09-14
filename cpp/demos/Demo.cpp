#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;
/*
    struct BitField
   {
      unsigned int a:4;  //占用4个二进制位;
      unsigned int  :0;  //空位域,自动置0;
      unsigned int b:4;  //占用4个二进制位,从下一个存储单元开始存放;
      unsigned int c:4;  //占用4个二进制位;
      unsigned int d:5;  //占用5个二进制位,剩余的4个bit不够存储4个bit的数据,从下一个存储单元开始存放;
      unsigned int  :0;  //空位域,自动置0;
      unsigned int e:4;  //占用4个二进制位,从这个存储单元开始存放;
   };
*/
int main(int argc, char *argv[])
{
    int i : 2;
    
    i = 2;
    
    cout<<i<<endl;
    
    return 1;
}
