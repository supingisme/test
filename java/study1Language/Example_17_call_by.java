/*
2017/5/4
*/
class test{
	int a;
	int b;
	test(){
		a=1;
		b=2;
	}
	test(int i){
		a=b=i;
	}
	test(int i,int j){
		a=i;
		b=j;
	}
	test(test o){
		a=o.a;
		b=o.b;
	}
	void fun(test o){
		o.a+=1;
		o.b-=1;
	}
}
class test1{
	int a;
	test1(int a){
		this.a=a;
	}
	test1 fun1(test1 o){
		test1 o1=new test1(o.a*10);
		return o1;
	}
}
class test2{
	int a;
	test2(int a){
		this.a=a;
	}
	public int fun2(int n){
		int sum=1;
		if(n<0) return -1;
		if(n==0)return 1;
		if(n==1)return 1;
		sum=fun2(n-1)*n;
		return sum;
	}
}
class test3{
	int a[];
	test3(int i){
		a=new int[i];
		int j;
		for(j=0;j<i;j++)a[j]=j+1;
	}
	protected void fun3(int i){
		if(i==0)return;
		else fun3(i-1);
		System.out.println("i="+(i-1)+" , a[i]="+a[i-1]);
	}	
}
class test4{
	int a;
	public int b;
	private int c;
	void seta(int a){
		this.a=a;
	}
	void setb(int b){
		this.b=b;
	}
	void setc(int c){
		this.c=c;
	}
}
class Example_17{
	public static void main(String args[])throws java.io.IOException{

		test t=new test(1);
		System.out.println("a="+t.a+",b="+t.b);
		t.fun(t);
		System.out.println("a="+t.a+",b="+t.b);

		test1 t1=new test1(1);
		System.out.println("a="+t1.a);
		t1=t1.fun1(t1);
		System.out.println("a="+t1.a);
		t1=t1.fun1(t1);
		System.out.println("a="+t1.a);

		test2 t2=new test2(5);
		System.out.println("t2.fun2="+t2.fun2(10));

		test3 t3=new test3(10);
		t3.fun3(10);

		test4 t4=new test4();
		t4.a=1;
		t4.b=2;
		//t4.c=3;
		t4.seta(4);
		t4.setb(5);
		t4.setc(6);


	}
}
