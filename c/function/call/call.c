void func1() 
{}

void func2() 
{
	func1();
}
void func3()
{
	func2();
}

int main()
{
	func3();
}
