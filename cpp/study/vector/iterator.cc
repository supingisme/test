#include <iostream>
#include <vector>
#include <string>
using namespace std;

string pooh_pals[] = {
	"Tigger", "Piglet", "Eeyore", "Rabbit"
};
int main()
{
	vector<string> ppals( pooh_pals, pooh_pals+2 );
	vector<string>::iterator iter = ppals.begin();
	vector<string>::iterator iter_end = ppals.end();
	
	cout << "These are Pooh's pals: ";
	
	for ( ; iter != iter_end; iter++ )
		cout << *iter << " ";
	
	cout << endl;
}
