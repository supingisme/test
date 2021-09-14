#include<iostream>
#include<map>

//#include<gtk/gtk.h>
//#include"Demo.h"
using namespace std;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.15 */ 
{
    /* multiset 和multimap 允许要被存储的键出现多次 */
    multimap< string, string > authors;
    string search_item( "rongtao" );

    authors.insert(multimap<string,string>::value_type(string("rongtao"),string("yes")));

    authors.insert(multimap<string,string>::value_type(string("Bob"),string("yes3")));
    authors.insert(multimap<string,string>::value_type(string("rongtao"),string("yes2")));

    int number = authors.count( search_item );
    multimap< string,string >::iterator iter;
    iter = authors.find( search_item );
    for ( int cnt = 0; cnt < number; ++cnt, ++iter )
        cout<<( *iter ).second<<endl;


    return 0;
}

