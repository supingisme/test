/*
2017/5/11
*/
class A implements Call{
	int a;
	A(int a){
		this.a=a;
	}
	public void fun1(String str){
		System.out.println("A:fun1: "+str);
	}
	public void fun2(String str){
		System.out.println("A:fun2: "+str);
	}
}
class Demo_main{
	public static void main(String[] args)throws java.io.IOException{
		
		Call call;
		Call c=new A(1);
		A a=new A(1);

		c.fun1("My");
		c.fun2("name is");
		a.fun1("Rong");
		a.fun2("Tao");

		call=c;
		call.fun1("a");
		call.fun2("b");
		call=a;
		call.fun1("c");
		call.fun2("d");
	}
}
