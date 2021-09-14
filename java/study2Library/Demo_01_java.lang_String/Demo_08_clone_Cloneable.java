/*
2017/5/31
*/
/*
class A implements Cloneable{
	int a,b;
	A test(){
		try{
			return (A)super.clone();
		}catch(Exception e){
			System.out.println("Clone error."+e);
			return this;
		}
	}
}
class Demo_08{
	public static void main(String[]args){
		A a1 = new A();
		A a2;
		a1.a = 10;
		a1.b = 11;
		a2 = a1.test();
		System.out.println("a1.a = "+a1.a+", a1.b = " +a1.b);
		System.out.println("a2.a = "+a2.a+", a2.b = " +a2.b);

		a1.a = 20;
		a1.b = 21;
		System.out.println("a1.a = "+a1.a+", a1.b = " +a1.b);
		System.out.println("a2.a = "+a2.a+", a2.b = " +a2.b);

	}
}*/
class A implements Cloneable{
	int a,b;
	public Object clone(){
		try{
			return super.clone();
		}catch(Exception e){
			System.out.println("Clone error."+e);
			return this;
		}
	}
}
class Demo_08{
	public static void main(String[]args){
		A a1 = new A();
		A a2;
		a1.a = 10;
		a1.b = 11;
		a2 = (A)a1.clone();
		System.out.println("a1.a = "+a1.a+", a1.b = " +a1.b);
		System.out.println("a2.a = "+a2.a+", a2.b = " +a2.b);

		a1.a = 20;
		a1.b = 21;
		System.out.println("a1.a = "+a1.a+", a1.b = " +a1.b);
		System.out.println("a2.a = "+a2.a+", a2.b = " +a2.b);

	}
}
