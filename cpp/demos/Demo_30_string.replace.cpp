#include<iostream>
#include<string>

using namespace std;

typedef string::size_type size_type;

int main(int argc, char*argv[])
/* Rong Tao 2018.03.14 */ 
{
    string sentence("Rong Tao's favorite sport is body building.");
    size_type position = sentence.find_last_of("T");
    length = 3;
    sentence.replace(position, length, "Toa");
    cout<<sentence<<endl;

    size_type posA = sentence.find("R");
    sentence.replace(position, 1, "new123123", posA, 9);
    cout<<sentence<<endl;

    return 0;
}

