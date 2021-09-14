#include <iostream>

using namespace std;

class bus {
public:
	int getNo();
	void setNo(int no);

private:
	int no;
};

int bus::getNo() {
	return this->no;
}
void bus::setNo(int no) {
	this->no = no;
}

int main() {

	bus b;

	b.setNo(123);
	cout<<b.getNo()<<endl;

	cout<<"rongtao"<<endl;
}
