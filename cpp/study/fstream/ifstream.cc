#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string ifile;
	cin >> ifile;

	ifstream infile(ifile.c_str());
	string ofile = ifile+".sort";
	ofstream outfile(ofile.c_str());

	string buffer;
	//vector<string,allocator> text;
	
	while(infile >> buffer)
	{
		cout<<buffer<<endl;
	}
}
