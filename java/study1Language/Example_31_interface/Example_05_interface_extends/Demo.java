/*
2017/5/11
*/
interface A{
	void fun1();
}
interface B extends A{
	void fun2();
}
class C implements B{
	int c;
	public void fun1(){
		System.out.println("C:fun1");
	}
	public void fun2(){
		System.out.println("C:fun2");
	}
}
class Demo{
	public static void main(String[] args){
	
		C c=new C();
		c.fun1();
		c.fun2();

	}
}
