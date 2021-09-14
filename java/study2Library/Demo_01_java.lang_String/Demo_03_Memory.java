// Demonstrate totalMemory(), freeMemory() and gc().
class Demo_03 {
	public static void main(String args[]) {

		Runtime r = Runtime.getRuntime();

		long mem1, mem2;
		Integer someints[] = new Integer[1000];

		System.out.println(r.totalMemory());

		mem1 = r.freeMemory();
		System.out.println(mem1);

		r.gc();
		mem1 = r.freeMemory();
		System.out.println(mem1);
		for(int i=0; i<1000; i++)
			someints[i] = new Integer(i); // allocate integers
		mem2 = r.freeMemory();
		System.out.println(mem2);
		System.out.println((mem1-mem2));
		// discard Integers
		for(int i=0; i<1000; i++) someints[i] = null;
		r.gc(); // request garbage collection
		mem2 = r.freeMemory();
		System.out.println(mem2);
	}
}
