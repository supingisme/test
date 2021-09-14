/*
2017/5/4
*/
class test{
	static int x;
	static void square(int a){
		System.out.println("a*a="+a*a);
	}
}
class Example_19{
	static int a=3;
	static int b;
	static void meth(int x){
		System.out.println("x="+x);
		System.out.println("a="+a);
		System.out.println("b="+b);
	}
	static{
		System.out.println("Static block initialized.");
		b=a*4;
	}

	public static void main(String args[])throws java.io.IOException{

		final int a=1;

		meth(42);
		test.square(9);

		a=2;
	}
}
