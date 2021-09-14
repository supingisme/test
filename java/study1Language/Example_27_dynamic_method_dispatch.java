/*
2017/5/9
*/
/*A B is for super , extends*/
class A{
	int a;
	A(){
		a=1;
	}
	A(int a){
		this.a=a;
	}
	void show(String str){
		System.out.println(str+": a = "+a);
	}
}
class B extends A{
	int b;
	B(){
		super();
		b=2;
	}
	B(int x){
		super(x);
		b=x;
	}
	B(int a,int b){
		super(a);
		this.b=b;
	}
	void show(String str){
		super.show(str);
		System.out.println(str+": a = "+a+" , b = "+b);
	}
}
/*C D E is for dynamic method dispatch*/
class C{
	void callme(){
		System.out.println("C's method.");
	}
}
class D extends C{
	void callme(){
		System.out.println("D.s method.");
	}
}	
class E extends D{
	void callme(){
		System.out.println("E.s method.");
	}
}
/*Using run-time polymorphism.*/
class Figure{
	double dim1;
	double dim2;
	Figure(double a,double b){
		dim1=a;
		dim2=b;
	}
	double area(){
		System.out.println("Area for Figure is undefine.");
		return 0;
	}
}
class Rectangle extends Figure{
	Rectangle(double a,double b){
		super(a,b);
	}
	double area(){
		System.out.println("Inside Area for Rectangle.");
		return dim1*dim2;
	}
}
class Triangle extends Figure{
	Triangle(double a,double b){
		super(a,b);
	}
	double area(){
		System.out.println("Inside Area for Triangle.");
		return dim1*dim2/2;
	}
}
/* main */
class Example_27{
	public static void main(String args[])throws java.io.IOException{

		/* angle */
		Figure f=new Figure(10,10);
		Rectangle r=new Rectangle(9,5);
		Triangle t=new Triangle(10,8);

		Figure figref;

		figref=r;
		System.out.println("Area is "+figref.area());
		figref=t;
		System.out.println("Area is "+figref.area());
		figref=f;
		System.out.println("Area is "+figref.area());

		/* A B */
		/*A a=new A(11);
		B b=new B(11,22);

		a.show("a");
		b.show("b");*/

		/* C D E */
		/*C c=new C();
		c.callme();

		D d=new D();
		d.callme();

		E e=new E();
		e.callme();

		C r=new C();
		r=c;
		r.callme();
		r=d;
		r.callme();
		r=e;
		r.callme();*/




	}
}
