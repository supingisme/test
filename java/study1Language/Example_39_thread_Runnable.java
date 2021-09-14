/*
2017/5/16
*/
// Create a second thread.
class NewThread implements Runnable{
	Thread t;
	NewThread(){
		// Create a new, second thread
		t=new Thread(this, "Demo");
		System.out.println("NewThread: "+t);
		t.start();
	}
	// This is the entry point for the second thread.
	public void run(){
		try{
			for( int i = 5 ; i > 0 ; i --) {
				System.out.println("run: "+i);
				Thread.sleep(500);
			}
		}catch(InterruptedException e){
			System.out.println("Child interrupted.");
		}
		System.out.println("Exiting child thread.");
	}
}
class Example_39{
	public static void main(String[] args)throws java.io.IOException{

		new NewThread();// create a new thread

		try{
			for ( int i = 5 ; i > 0 ; i --){
				System.out.println("Main Thread: "+i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			System.out.println("Main thread interrupted.");
		}
		System.out.println("Main thread Exiting.");
	}
}
