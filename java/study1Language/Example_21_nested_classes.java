/*
2017/5/4
*/
class outer{
	int outx=100;
	void test(){
		inner1 in1=new inner1();
		in1.display1();
		System.out.println("outer class display. outx= "+outx);
	}
	class inner1{
		int inx=200;
		void display1(){
			System.out.println("inner1 class display. outx= "+outx);
			test2();
		}
		void test2(){
			for(int i=0;i<5;i++){
				class inner2{
					void display2(){
						System.out.println("inner2 class display. inx= "+inx);
					}	
				}
				inner2 in2=new inner2();
				in2.display2();
			}
		}	

	}

}
class Example_21{
	public static void main(String args[])throws java.io.IOException{
		
		outer out=new outer();
		out.test();

	}
}
