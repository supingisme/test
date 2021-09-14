#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

#include <functional>/*预定义函数对象*/

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vi;
    int i[5] = {2,1,3,5,4};
    vi.insert(vi.end(), i, i+5);
    
    for(auto i : vi)
        cout<<i<<endl;
    
    sort(vi.begin(), vi.end(), greater<int>());
    
    for(auto i : vi)
        cout<<i<<endl;
    
    return 1;
}
