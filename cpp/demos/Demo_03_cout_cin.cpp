#include<iostream>
#include<string>
using namespace std;

/**
int main(){

    string filename1, filename2;

    cin>>filename1>>filename2;
    cout<<filename1<<filename2;

    string a;
    while(cin>>a){

        cout<<a;
    }

    return 0;
}
*/
int main()
{
    string word;
    while ( cin >> word )
        cout << "word read is: " << word << '\n';
    cout << "ok: no more words to read: bye!\n";
    return 0;
}
