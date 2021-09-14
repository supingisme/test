/*
2017/5/3
*/
/*overload*/
class overload{
	void test(){
		System.out.println("test1");
	}
	int test(int a,int b){
		return a+b;
	}
	double test(double a,double b){
		return a+b;
	}
	double test(double a){
		return a;
	}
}
class Box{
	double x;
	double y;
	Box(){
		x=1.0;
		y=2.0;
	}
	Box(double x,double y){
		this.x=x;
		this.y=y;
	}
	Box(double len){
		x=y=len;
	}
	Box(Box box){
		x=box.x;
		y=box.y;
	}

	void square(){
		System.out.println("square="+x*y);
	}
}
class test{
	int a,b;
	test(){
		a=1;
		b=2;
	}
	test(int c){
		a=b=c;
	}
	test(int a,int b){
		this.a=a;
		this.b=b;
	}
	test(test i){
		a=i.a;
		b=i.b;
	}
	boolean equals(test t){
		if(t.a==a&&t.b==b)
			return true;
		else return false;
	}
}
class Example_16{
	public static void main(String args[])throws java.io.IOException{
	
		overload ol=new overload();
		ol.test();
		System.out.println("a+b="+ol.test(1,2)+",a.0+b.0="+ol.test(2.0,3.0)+",a.0="+ol.test(1));

		Box box1=new Box();
		Box box2=new Box(5);
		Box box3=new Box(box2);

		box1.square();
		box2.square();
		box3.square();

		test t1=new test(1);
		test t2=new test(t1);
		test t3=new test(2,3);
		System.out.println("t1==t2:"+t1.equals(t2));
		System.out.println("t2==t1:"+t2.equals(t1));
		System.out.println("t1==t1:"+t1.equals(t1));
		System.out.println("t2==t3:"+t2.equals(t3));
		System.out.println("t1==t3:"+t1.equals(t3));


	}
}
