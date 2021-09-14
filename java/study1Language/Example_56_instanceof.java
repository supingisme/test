/*
2017/5/25
*/
class A{
	int a;
}
class B{
	int b;
}
class Example_56{
	public static void main(String[]args){
		A a = new A();
		B b = new B();

		System.out.println((a instanceof A));
		System.out.println((b instanceof B));
		//System.out.println((a instanceof B));
	}
}
