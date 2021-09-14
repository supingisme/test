/*
2017/5/10
*/
package p4;

class B extends p3.A{
	int b;
	B(){
		super();
		b=2;
	}
	B(int len){
		super(len);
		b=len;
	}
	B(int a,int b){
		super(a);
		this.b=b;
	}
	void show(int x){
		System.out.println("B: a = "+a+", b = "+b);
	}
}
