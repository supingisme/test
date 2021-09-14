/*
2017/5/9
*/
package p1;

class B extends A{
	int b;
	B(int x,int y){
		super(x);
		b=y;
		System.out.println("B:a = "+a+", b = "+b);
	}
}
