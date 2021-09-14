/*
2017/5/9
*/
package p2;

class C extends p1.A{
	int c;
	C(int x,int c){
		super(x);
		this.c=c;
		System.out.println("C:a = "+a+", c = "+c);
	}
}
