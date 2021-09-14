/*
2017/5/16
*/
class NewThread implements Runnable{
	String name;
	Thread t;

	NewThread(String threadname){
		name = threadname;
		t = new Thread(this,name);
		System.out.println("NewThread: "+t);
		t.start();
	}
	public void run(){
		try{
			for ( int i = 5 ; i > 0 ; i -- ) {
				System.out.println(name+": "+i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			System.out.println("Interrupted: "+e);
		}
	}
}
class Example_41{
	public static void main(String[]args){
	
		new NewThread("One");
		new NewThread("Two");
		new NewThread("Three");

	}
}
