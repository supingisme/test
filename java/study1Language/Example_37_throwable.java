/*
2017/5/12
*/
class RongtaoException extends Exception{
	private int detail;
	RongtaoException(int a){
		detail=a;
	}
	public String toString(){
		return "RongtaoException ["+detail+"]";
	}
}

class Example_37{
	static void compute(int a) throws RongtaoException{
		System.out.println("compute: a = "+a);
		if(a>10)
			throw new RongtaoException(a);
		System.out.println("Normal Exit.");
	}
	public static void main(String[]args){

		try{
			compute(1);
			compute(15);
		}catch(RongtaoException e){
			System.out.println(e);
		}finally{
			System.out.println("finally.");
		}

	}
}
