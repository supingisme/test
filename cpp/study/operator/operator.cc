#include <iostream>


class WordCount {
	friend ostream&
		operator<<(ostream&, const WordCount&);
public:
	WordCount( string word, int cnt=1 );

private:
	string word;
	int occurs;
};

ostream&
operator <<( ostream& os, const WordCount& wd )
{ /* 格式: <occurs> word*/
	os << "< " << wd.occurs << " > "<< wd.word;
	return os;
}

int main()
{
	std::string str("sadness");
	WordCount wd(str);
	cout << "wd:\n" << wd << endl;
	return 0;
}
