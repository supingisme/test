/*
2017/5/9
*/
abstract class A{
	abstract void callme();
	void callmetoo(){
		System.out.println("A:callmetoo.");
	}
}
class B extends A{
	void callme(){
		System.out.println("B:callme.");
	}
}
abstract class Figure{
	double x,y;
	Figure(double x,double y){
		this.x=x;
		this.y=y;
	}
	abstract void area();
}
class Triangle extends Figure{
	Triangle(double x,double y){
		super(x,y);
	}
	void area(){
		System.out.println("Triangle area is: "+x*y);
	}
}
class Rectangle extends Figure{
	Rectangle(double x,double y){
		super(x,y);
	}
	void area(double a){
		System.out.println("Rectangle area is: "+x*y/2);
	}
	void area(){
		System.out.println("Rectangle area is: "+x*y/2);
	}
}
//final class C{}
//class D extends C{}
class Example_28{
	public static void main(String args[])throws java.io.IOException{
		
		//A a=new A();//error
		/*B b=new B();
		b.callme();
		b.callmetoo();*/
	
		Triangle t=new Triangle(2,3);
		Rectangle r=new Rectangle(2,3);
		t.area();
		r.area(1);

	}
}
