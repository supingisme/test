/*
2017/5/23
*/
// An incorrect implementation of a producer and consumer.
class Q {
	int n;
	synchronized void get() {
		System.out.println("Got: " + n);
	}
	synchronized void put(int n) {
		this.n = n;
		System.out.println("Put: " + n);
	}
}
class Producer implements Runnable {
	Q q;
	Producer(Q q) {
		this.q = q;
		new Thread(this, "Producer").start();
	}
	public void run() {
		int i = 0;
		while(q.n<4) {
			q.put(i++);
		}
	}
}
class Consumer implements Runnable {
	Q q;
	Consumer(Q q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}
	public void run() {
		while(q.n<4) {
			q.get();
		}
	}
}
class Example_45 {
	public static void main(String args[]) {
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
		System.out.println("Press Control-C to stop.");
	}
}
