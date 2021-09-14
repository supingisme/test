/*
2017/5/23
*/
// A correct implementation of a PUT and GET.
/*
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
*/
class Q {
	int n=3;
	boolean valueSet = false;
	synchronized void get() {
		if(!valueSet)
		try {
			wait();
		} catch(InterruptedException e) {
			System.out.println("InterruptedException caught");
		}
		System.out.println("Got: " + n);
		valueSet = false;
		notify();
	}
	synchronized void put(int n) {
		if(valueSet)
		try {
			wait();
		} catch(InterruptedException e) {
			System.out.println("InterruptedException caught");
		}
		this.n = n;
		valueSet = true;
		System.out.println("Put: " + n);
		notify();
	}
}
class PUT implements Runnable {
	Q q;
	PUT(Q q) {
		this.q = q;
		new Thread(this, "PUT").start();
	}
	public void run() {
		int i = 0;
		while(q.n<4) {
			q.put(i++);
		}
	}
}
class GET implements Runnable {
	Q q;
	GET(Q q) {
		this.q = q;
		new Thread(this, "GET").start();
	}
	public void run() {
		while(q.n<4) {
			q.get();
		}
	}
}
class Example_46 {
	public static void main(String args[]) {
		Q q = new Q();
		new PUT(q);
		new GET(q);

	}
}
