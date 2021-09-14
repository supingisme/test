/*
2017/5/6
*/
class Box{
	double x,y,z;
	Box(){
		x=y=z=1;
	}
	Box(double len){
		x=y=z=len;
	}
	Box(double x, double y,double z){
		this.x=x;
		this.y=y;
		this.z=z;
	}
	void volume(String str){
		System.out.println(str+" volume = "+(x*y*z));
	}	
}
class Cube extends Box{
	double d;
	Cube(){
		super();
		d=1;
	}
	Cube(double len,double d){
		super(len);
		this.d=d;
	}
	Cube(double x,double y,double z,double d){
		super(x,y,z);
		this.d=d;
	}
	void weight(String str){
		System.out.println(str+" weight = "+(x*y*z*d));
	}
}
class Cost extends Cube{
	double c;
	Cost(){
		super();
		c=2.0;
	}
	Cost(double len,double d,double c){
		super(len,d);
		this.c=c;
	}
	Cost(double x,double y,double z,double d,double c){
		super(x,y,z,d);
		this.c=c;
	}
	void cost(String str){
		System.out.println(str+" cost = "+(x*y*z*d*c));
	}
}
class A{
	int i;
}
class B extends A{
	int i;
	B(int a,int b){
		super.i=a;
		i=b;
	}
	void show(String str){
		System.out.println(str+" i in A: "+super.i);
		System.out.println(str+" i in B: "+i);
	}
}
class C{
	C(){
		System.out.println("C");
	}
}
class D extends C{
	D(){
		System.out.println("D");
	}
}
class E extends D{
	E(){	
		System.out.println("E");
	}
}
class Example_25{
	public static void main(String args[])throws java.io.IOException{

		Box box=new Box(1,2,3);
		box.volume("box's");

		Cube cube=new Cube(2,3,4,2);
		cube.volume("cube's");
		cube.weight("cube's");

		box=cube;
		box.volume("after box's");

		A a=new A();
		B b=new B(1,2);
		b.show("b: ");

		Cost c=new Cost(1,2,3,4,5);
		c.cost("c: ");

		E e=new E();
		





	}
}
