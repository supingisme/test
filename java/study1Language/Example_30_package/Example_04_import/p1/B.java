/*
2017/5/10
*/
package p1;

public class B extends A{
	public int b;
	public B(){
		super();
	}
	public B(int len){
		a=len;
		b=len;
	}
	public B(int a,int b){
		super(a);
		this.b=b;
	}
	public void show(){
		System.out.println("B: a = "+a+", b = "+b);
	}	
	public void show(int a,int b){
		System.out.println("B2:");
	}
}
