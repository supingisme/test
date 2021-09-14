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

using namespace std;

template<typename elemType>
bool Comp(elemType a, elemType b)
{
    return strcmp(a,b);
}
int main(int argc, char*argv[])
/* Rong Tao 2018.03.13 */
{
    vector< int > ivec;
    cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;
    for ( int ix = 0; ix < 24; ++ix ) {
        ivec.push_back( ix );
        cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;
    }

    list<string> ilist;
    if(ilist.empty() != true) cout<<"true"<<endl;

    string str;
    while(cin>>str){
        if(str == "quit")break;
        ilist.push_back(str);
    }
    ilist.sort();
    list<string>::iterator iter;
    for(iter = ilist.begin();iter != ilist.end();iter++)
        cout<<*iter<<endl;


    return 0;
}

