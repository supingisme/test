/*
2017/5/16
*/
class Example_38{
	public static void main(String[] args)throws java.io.IOException{

		Thread t=Thread.currentThread();
		System.out.println("Current Thread: "+t);

		t.setName("Rong");
		System.out.println("After named: "+t);

		try{
			for( int i = 7 ; i > 0 ; i --) {
				System.out.println(i);
				Thread.sleep(10);
			}
		}catch(InterruptedException e){
			System.out.println("Main thread interrupted.");
		}

	}
}
