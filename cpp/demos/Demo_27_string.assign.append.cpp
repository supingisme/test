#include<iostream>
#include<string>

using namespace std;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.14 */ 
{
    string s1( "Mississippi" );
    string s2( "Annabelle" );

    string s3;

    s3.assign( s1, 0, 4 );
    s3 += ' ';
    s3.append( s2, 0, 4 );
    cout<<s3<<endl;
    s3.assign( s1, 0, 4 ).append( " " ).append( s2, 0, 4 );

    cout<<s3<<endl;
    

    return 0;
}

