/*
2017/5/12
*/
class Example_36{
	static void A(){
		try{
			System.out.println("A:try");
			throw new RuntimeException("woshinidaye");
		}finally{
			System.out.println("A:finally");
		}
	}
	static void B(){
		try{
			System.out.println("B:try");
			return;
		}finally{
			System.out.println("B:finally");
		}
	}
	static void C(){
		try{
			System.out.println("C:try");
		}finally{
			System.out.println("C:finally");
		}
	}
	public static void main(String[]args){
		try{
			A();
		}catch(Exception e){
			System.out.println(e);
		}
		B();
		C();
	}
}
