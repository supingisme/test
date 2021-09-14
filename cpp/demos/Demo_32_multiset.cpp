#include<iostream>
#include<string>
#include<set>
#include<iterator>

using namespace std;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.15 */ 
{
    /* multiset 和multimap 允许要被存储的键出现多次 */
    multiset<string> ms;
    string search("rong");
    
    ms.insert(multiset<string>::value_type(string("rong")));
    ms.insert(multiset<string>::value_type(string("rong")));
    ms.insert(multiset<string>::value_type(string("tao")));
    ms.insert(string("rong"));
    
    multiset<string>::iterator iter = ms.find(search);
    int count = ms.count(search);
    for(int j = 0; j<count;j++,++iter)
        cout<<j<<"/"<<count<<": "<<(*iter)<<endl;

    


    return 0;
}

