/*
2017/6/1
*/
import java.util.*;

class Demo_02{

	public static void main(String[]args){

		LinkedList ll = new LinkedList();

		ll.add("A");
		ll.add("B");
		ll.add("C");

		ll.addFirst("D");
		ll.addLast("E");

		ll.add(1,"A2");

		System.out.println("ll : "+ll);

		ll.removeFirst();

		System.out.println("ll : "+ll);

		ll.removeLast();

		System.out.println("ll : "+ll);

		Object val = ll.get(2);

		ll.set(2,(String)val +" Changed");

		System.out.println("ll : "+ll);

	}
}
