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
#include<assert.h>
#include<cstdlib>//abort()
#include<list>
#include<map>
#include<deque>
#include<set>
#include<iterator>
#include<exception>
#include<stack>
#include<queue>

#include<ctype.h>//atoi()

using namespace std;

extern int Init_Paras(int argc, char **argv)
{
    
}
/*
class CommandOpt {
public:
    CommandOpt() : _limit( -1 ), _debug_on( false ) {}
    int parse_options( int argc, char *argv[] );
    string out_file() { return _out_file; }
    bool debug_on() { return _debug_on; }
    int files() { return _file_names.size(); }
    // 访问 _file_names
    string& operator[]( int ix );
private:
    inline int usage( int exit_value = 0 );
    bool _debug_on;
    int _limit;
    string _out_file;
    vector<string, allocator> _file_names;
    static const char *const program_name;
    static const char *const program_version;
};*/

int main(int argc, char*argv[])
/* Rong Tao 2018.03.17 */ 
{
    Init_Paras(argc,argv);
    return 0;
}

