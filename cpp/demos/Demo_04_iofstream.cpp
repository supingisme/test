#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){

    ofstream outfile("b.txt");
    
    if(!outfile)
        cout<<"can not open file\n";

    ifstream infile("a.txt");
    /* a.txt
    word read is: rong
    */
    if(!infile)
        cout<<"can not open file\n";

    string word;
    while(infile>>word){
        cout<<"in:"<<word<<"\n";
        outfile<<word;
    }
    cout<<"print"<<endl;
    system("more a.txt && more b.txt");
}
