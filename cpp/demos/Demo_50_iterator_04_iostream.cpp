#include <iostream>
#include <string>
#include <vector>
#include <list>
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
    istream_iterator< int > input( cin );
    istream_iterator< int > end_of_stream;
    vector<int> vec;
    copy ( input, end_of_stream, inserter( vec, vec.begin() ));
    sort( vec.begin(), vec.end(), greater<int>() );
    ostream_iterator< int > output( cout, " " );
    unique_copy( vec.begin(), vec.end(), output );
    
    return 1;
}
