/* Rong Tao 2018.1.16 */
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>

using namespace std;
typedef vector<int>::iterator vii;
typedef vector<int> vector_int;
int main(int argc, char*argv[])
{
    int ia[ 6 ] = { -2, -1, 0, 1, 2, 1024 };

    /* #include<vector> */
    vector_int ivec1(2);//={1,2}//不能用同样的方法显式地初始化vector
    vector<int> ivec2(2,-1);//它包含2个int 型的元素,每个元素都被初始化为-1
    vector<int> ivec3( ia+1, ia+6 );
    vector<int> ivec4(ivec3);

    cout<<ivec1.size()<<ivec2.empty()<<endl;

    cout<<ivec3[3]<<endl;
    cout<<ivec4[3]<<endl;

    vector<int> ivec5;
    ivec5.push_back(1);
    ivec5.push_back(2);
    ivec5.push_back(3);
    ivec5.push_back(3);
    ivec5.push_back(1111);
    ivec5[1] = 1024;
    cout<<ivec5[1]<<endl;

    cout << "ivec5 are: \n";
    for ( vii it = ivec5.begin(); it != ivec5.end(); ++it )
        cout << *it << ' ';
    cout << endl;

    return 0;
}
