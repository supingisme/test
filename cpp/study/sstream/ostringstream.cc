#include <iostream>
#include <string>

using namespace std;

string name("program");
string version("1.0");

string mumble()
{
	if(1)
	{
		std::ostringstream outmsg;
		outmsg<<"error: "
			<<name<<"---"<<version<<__FILE__<<__LINE__<<endl;
		return outmsg.str();
	}
}

int main()
{
	cout<<mumble()<<endl;
}
