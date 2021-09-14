#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <complex>
#include <exception>
#include <algorithm>
#include <iterator>
#include <functional>/*预定义函数对象*/
#include <bitset>

using namespace std;

/**
$ ./a.exe
1 2 3 4 5 6 7 8 1 2 3 4 3 2 1 2 3 4 5 6>>
8 7 6 5 4 3 2 1
*/
int main(int argc, char *argv[])
{
    // 从标准输入读入一个 int对象的序列
    istream_iterator< int > is_int( cin );
    
    // 从命名的文件中读入一个字符串序列
    ifstream infile( argv[1] );
    istream_iterator< string > is_string( infile );
    
    // 构造一个 end-of-stream iterator 用作 iterator 对的结束标记 ...
    istream_iterator< string > end_of_stream;
    
    vector<string> text;
    // Ok: 提供 iterator 对
    copy( is_string, end_of_stream,inserter( text, text.begin() ));
    
    for(auto i : text)
        cout<<i<<endl;
    
    return 1;
}
