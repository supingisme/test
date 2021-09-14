/*
2017/5/12
*/
class Example_35{
	static void throwone()throws IllegalAccessException{
		System.out.println("Inside throwOne.");
		throw new IllegalAccessException("woshinidaye");
	}
	public static void main(String[] args){
		try{
			throwone();
		}catch(IllegalAccessException e){
			System.out.println(e);
		}
	}
}
