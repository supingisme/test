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

int main(int argc, char *argv[])
{
   /* copy( istream_iterator< int >( cin ),
          istream_iterator< int >(),
          ostream_iterator< int >( cout )); */
    
    string file_name;
    cout << "please enter a file to open: ";
    cin >> file_name;
    if ( file_name.empty() || !cin ) {
        cerr << "unable to read file name \n"; return -1;
    }
    ifstream infile( file_name.c_str());
    if ( ! infile ) {
        cerr << "unable to open " << file_name << endl;
        return -2;
    }
    istream_iterator< string > ins( infile ), eos;
    ostream_iterator< string > outs( cout, " " );
    copy( ins, eos, outs );
    
    return 1;
}
