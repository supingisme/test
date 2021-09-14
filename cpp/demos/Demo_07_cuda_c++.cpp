#include<iostream>
#include<string>
#include<cmath>
#include<complex>
using namespace std;

__global__ void  fun(int n, int *a)
{

    const int id = threadIdx.x + blockDim.x*blockIdx.x;

    if(id<n)
        (*a) += 1;

}

int pow(int a, int b)
{
    if(b<1)
        return 1;
    else
        return a*pow(a,b-1);
}

int main(int argc, char*argv[])
{

    cout<<pow(2,5)<<endl;

    int a(10);
    string str("rong");
    cout<<a<<str<<endl;

    complex<double> *cp ;
    cout<<*cp<<endl;

    a = 0;
    fun<<<1,5>>>(5,&a);
    cout<<a<<endl;

    return 0;
}
