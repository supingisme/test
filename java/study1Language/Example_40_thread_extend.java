/*
2017/5/16
*/
// Create a second thread by extending Thread
class NewThread extends Thread{
	NewThread(){
		super("Demo");
		System.out.println("Child thread: "+this);
		start();
	}
	// this is the entry point for the second thread.
	public void run(){
		try{
			for ( int i = 5 ; i > 0 ; i --) { 
				System.out.println("run: "+i);
				Thread.sleep(500);
			}
		}catch(InterruptedException e){
			System.out.println("Child interrupted.");
		}
	}
}

class Example_40{
	public static void main(String[] args)throws java.io.IOException{

		new NewThread();

		try {
			for ( int  i  = 5 ; i > 0 ; i -- ) {
				System.out.println("Main Thread: " + i);
				Thread.sleep(1000);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted.");
		}
		System.out.println("Main thread exiting.");
	}
}
