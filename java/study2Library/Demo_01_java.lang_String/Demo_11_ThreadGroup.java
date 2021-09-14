// Demonstrate thread groups.
/*
这在想挂起或
恢复一些相关的线程的情况下，是特别有用的。例如假想在一个程序中，有一组线程被用
来打印文档，另一组线程被用来将该文档显示在屏幕上，同时另一组线程将文档保存为磁
盘文件。如果打印被异常中止了，想用一种很简单的方法停止所有与打印有关的线程。线
程组为这种处理提供了方便。
*/
class NewThread extends Thread {
	boolean suspendFlag;
	NewThread(String threadname, ThreadGroup tgOb) {
		super(tgOb, threadname);
		System.out.println("New thread: " + this);
		suspendFlag = false;
		start(); // Start the thread
	}
	// This is the entry point for thread.
	public void run() {
		try {
			for(int i = 5; i > 0; i--) {
				System.out.println(getName() + ": " + i);
				Thread.sleep(1000);
				synchronized(this) {
					while(suspendFlag) {
						wait();
					}
				}
			}
		} catch (Exception e) {
			System.out.println("Exception in " + getName());
		}
		System.out.println(getName() + " exiting.");
	}
	void mysuspend() {
		suspendFlag = true;
	}
	synchronized void myresume() {
		suspendFlag = false;
		notify();
	}
}
class Demo_11 {
	public static void main(String args[]) {
		ThreadGroup groupA = new ThreadGroup("Group A");
		ThreadGroup groupB = new ThreadGroup("Group B");
		NewThread ob1 = new NewThread("One", groupA);
		NewThread ob2 = new NewThread("Two", groupA);
		NewThread ob3 = new NewThread("Three", groupB);
		NewThread ob4 = new NewThread("Four", groupB);
		System.out.println("\nHere is output from list():");
		groupA.list();
		groupB.list();
		System.out.println();
		System.out.println("Suspending Group A");
		Thread tga[] = new Thread[groupA.activeCount()];
		groupA.enumerate(tga); // get threads in group
		for(int i = 0; i < tga.length; i++) {
			((NewThread)tga[i]).mysuspend(); // suspend each thread
		}
		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted.");
		}
		System.out.println("Resuming Group A");
		for(int i = 0; i < tga.length; i++) {
			((NewThread)tga[i]).myresume(); // resume threads in group
		}
		// wait for threads to finish
		try {
			System.out.println("Waiting for threads to finish.");
			ob1.join();//wain for thread termination
			ob2.join();
			ob3.join();
			ob4.join();
		} catch (Exception e) {
			System.out.println("Exception in Main thread");
		}
			System.out.println("Main thread exiting.");
	}
}
