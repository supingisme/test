/*
2017/5/12
*/
class Example_34{
	static void demoproc(){
		try{
			throw new NullPointerException(" woshinidaye");
		}catch(NullPointerException e){
			System.out.println("Demo Error: "+e);
			throw e;
		}
	}

	public static void main(String[]args)throws java.io.IOException{

		try{
			demoproc();
		}catch(NullPointerException e){
			System.out.println("Error Main: "+e);
		}
	}
}
