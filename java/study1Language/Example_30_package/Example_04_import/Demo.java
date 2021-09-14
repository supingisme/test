/*
2017/5/10
*/
import p1.A;
import p1.B;

class Demo{
	public static void main(String args[]){
	
		A a=new A(2);
		a.show();

		B b=new B(2,3);
		b.show();
		b.show(1,2);

		a=b;
		a.show();
	}
}
