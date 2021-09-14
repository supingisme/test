#include<iostream>
#include<string>
using namespace std;



int main(int argc, char*argv[])
/* Rong Tao 2018.03.14 */ 
{
    string sentence("Rong Tao's favorite sport is body building.");
    string::size_type position = sentence.find_last_of("T",8);
    int length = 3;
    sentence.replace(position, length, "Toa");
    cout<<sentence<<endl;

    return 0;
}

