/*
2017/5/10
*/
interface Callback{
	void callback(int parem);
}
class Client implements Callback{
	//Implement Callback's interface
	public void callback(int p){
		System.out.println("Client: p = "+p);
	}
	void nonIfaceMeth(){
		System.out.println("Classes that inplement interface" +
					"may also define other members, too.");
	}
}
class AnotherClient implements Callback{
	//Another implementation of Callback
	//Implement Callback's interface
	public void callback(int p){
		System.out.println("AnotherClient: p*p = "+p*p);
	}
}
/* abstract class for interface */
interface Call{
	void fun1(int a);
	void fun2(int a);
}
abstract class A implements Call{
	int a;
	public void fun1(int b){
		System.out.println("A: b = "+b);
	}
}
class B extends A {
	public void fun2(int b){
		System.out.println("B: b = "+b);
	}
}
class TestIface{
	public static void main(String[] args){
		Callback c=new Client();
		c.callback(42);
		//c.nonIfaceMesh();//ERROR

		Client a=new Client();
		a.callback(2);

		AnotherClient b=new AnotherClient();
		b.callback(3);

		c=a;
		c.callback(4);
		c=b;
		c.callback(5);

		B bb=new B();
		bb.fun1(1);
		bb.fun2(2);

		Call cc=new B();
		cc.fun1(5);
		cc.fun2(6);
	}
}	
