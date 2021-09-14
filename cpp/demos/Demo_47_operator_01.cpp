#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector<string> textwords;

class LessThan {
public:
    bool operator()( const string & s1, const string & s2 )
    { return s1.size() < s2.size(); }
};

int main(int argc, char *argv[])
{
    int a[5] = {1,4,5,2,3};

    vector<int> va(a[0], a[4]);
    
    cout<<*find(&a[0], &a[4], 4);
    
    LessThan lt;
    string st1( "shakespeare" );
    string st2( "marlowe" );
    
    cout<< lt( st1, st2 );// 调用 lt.operator()( st1, st2 );
    cout<< lt.operator()( st1, st2 );//这两句完全一样
    
    return 1;
}
