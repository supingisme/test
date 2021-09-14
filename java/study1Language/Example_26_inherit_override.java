/* 
2017/5/6
*/
class A{
	int a;
	A(int a){
		this.a=a;
	}
	void show(String str){
		System.out.println(str+" a = "+a);
	}
}
class B extends A{
	int b;
	B(int a,int b){
		super(a);
		this.b=b;
	}
	void show(){
		System.out.println(" a = "+a+", b = "+b);
	}
}
class Example_26{
	public static void main(String args[])throws java.io.IOException{

		B b=new B(1,2);
		b.show("b: ");
		b.show();


	}
}
