/*
2017/5/4
creat superclass & subclass
box volume ---> box weight
*/
class A{
	int a;
	private int a0;
	A(){
		a=1;
	}
	A(int a){
		this.a=a;
		a0=a;
	}
	A(int a,int a0){
		this.a=a;
		this.a0=a0;
	}
	void showa(){
		System.out.println("A: a = "+a+", a0 = "+a0);
	}
}
class B extends A{
	int b;
	B(){
		a=b=1;
	}
	B(int c){
		a=b=c;
	}
	B(int a,int b){
		this.a=a;
		this.b=b;
	}
	void showb(){
		System.out.println("B: b = "+b);
	}
	void sumab(){
		System.out.println("B: a+b = "+(a+b));
	}
}
class Boxvolume{
	double width;
	double height;
	double depth;
	Boxvolume(Boxvolume box){
		width=box.width;
		height=box.height;
		depth=box.depth;
	}
	Boxvolume(){
		width=height=depth=10.0;
	}
	Boxvolume(double cube){
		width=height=depth=cube;
	}
	void volume(){
		System.out.println("Box volume is : "+(width*height*depth));
	}
}
class Boxweight extends Boxvolume{
	double density;
	Boxweight(){
		width=height=depth=10.0;
		density=1.5;
	}
	Boxweight(double cube,double density){
		width=height=depth=cube;
		this.density=density;
	}
	void weight(){
		System.out.println("Box weight is : "+(width*height*depth*density));
	}
}
class Example_23{
	public static void main(String args[])throws java.io.IOException{
		A a=new A(11);
		a.showa();

		B b=new B(12,23);
		b.a=2;
		b.b=3;
		b.showa();
		b.showb();
		b.sumab();

		Boxvolume boxvolume=new Boxvolume(10.0);
		boxvolume.width=10;
		boxvolume.height=20;
		boxvolume.depth=30;
		boxvolume.volume();

		Boxweight boxweight=new Boxweight(12,2.5);
		boxweight.volume();
		boxweight.weight();

	}
}
