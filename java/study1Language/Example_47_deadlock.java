/*
2017/5/23
*/
// An example of deadlock.
class A {
	synchronized void funA(B b) {
		String name = Thread.currentThread().getName();
		System.out.println(name + ": A.funA");//111111111
		try {
			Thread.sleep(5000);
		} catch(Exception e) {}
		System.out.println(name + ": call B.last()");//333333333
		b.last();
	}
	synchronized void last() {
		System.out.println("Inside A.last");
	}
}
class B {
	synchronized void funB(A a) {
		String name = Thread.currentThread().getName();
		System.out.println(name + ": B.funB");//2222222222
		try {
			Thread.sleep(5000);
		} catch(Exception e) {}
		System.out.println(name + ": call A.last()");//4444444444
		a.last();
	}
	synchronized void last() {
		System.out.println("Inside A.last");
	}
}
class Deadlock implements Runnable {
	A a = new A();
	B b = new B();
	Deadlock() {
		Thread.currentThread().setName("thread1");
		Thread t = new Thread(this, "thread2");
		t.start();
		a.funA(b); // get lock on a in this thread.
		System.out.println("Back in main thread1");
	}
	public void run() {
		b.funB(a); // get lock on b in other thread.
		System.out.println("Back in other thread2");
	}
}
class Example_47{
	public static void main(String args[]) {
		new Deadlock();
	}
}
