/* Rong Tao 2018.1.16 */
#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef pair<string, int> pair_score;

typedef pair<string, int> p_person;

typedef pair<p_person, p_person> ppp;

int main(int argc, char*argv[])
{
    pair_score score("rong",100);

    cout<<score.first
        <<score.second        
        <<endl;
    
    p_person rt("rongtao", 27);
    cout<<rt.first<<rt.second<<endl;
        
    ppp rrtt(rt, rt);
    cout<<rrtt.first.first
        <<rrtt.second.second
        <<endl;
    
    vector<int> v_int;
    if(v_int.empty())
    {
        v_int.insert(v_int.begin(), 3);
    }
    cout<<v_int[0]<<endl;
    
    return 0;
}
