/* Rong Tao 2018.1.16 */
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>
#include<utility>
#include <cstddef> /*size_t*/

using namespace std;

int main(int argc, char*argv[])
{
    int *pi = new int;//int *
    int *pi2 = new(nothrow) int(123);//int
    int *pi3 = new int[123];//int
    int **pi4 = new int*[10]; //array

    cout<<*pi2<<endl;

    delete pi;
    delete pi2;
    delete []pi3;
    delete []pi4;

    cout<<*pi2<<endl;

    return 0;
}
